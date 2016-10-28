//
//  UMGSMMAP_Dialog.m
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import "UMLayerGSMMAP_Dialog.h"
#import "UMLayerGSMMAP.h"

@implementation UMLayerGSMMAP_Dialog

#pragma mark -
#pragma mark Properties

@synthesize userDialogId;
@synthesize tcapTransactionId;
@synthesize userIdentifier;
@synthesize mapUser;
@synthesize tcapLayer;
@synthesize gsmmapLayer;
@synthesize applicationContext;
@synthesize applicationContext2;
@synthesize options;
@synthesize callingAddress;
@synthesize calledAddress;
@synthesize userInfo;
@synthesize variant;
@synthesize tcapRemoteTransactionId;

@synthesize initiatedOutgoing;
@synthesize openEstablished;
@synthesize returnResultLastSent;
@synthesize dialogResponseRequired;
@synthesize dialogIsClosed;

#pragma mark -
#pragma mark Initialisation


- (UMLayerGSMMAP_Dialog *)init
{
    self = [super init];
    if(self)
    {
        lastInvokeId = 0;
        pendingOutgoingComponents = [[UMSynchronizedArray alloc]init];
        timeoutValue = 90;
        createdDate = [NSDate dateWithTimeIntervalSinceNow:0];
        timeoutDate = [NSDate dateWithTimeIntervalSinceNow:timeoutValue];
    }
    return self;
}


- (int64_t)nextInvokeId
{
    lastInvokeId = lastInvokeId +1;
    lastInvokeId = lastInvokeId % 0xFF;
    return lastInvokeId;
}

- (NSString *)getNewUserDialogId
{
    return NULL;
}

- (void)tcapBeginIndication:(NSString *)userDialogId
          tcapTransactionId:(NSString *)localTransactionId
    tcapRemoteTransactionId:(NSString *)remoteTransactionId
                    variant:(UMTCAP_Variant)var
             callingAddress:(SccpAddress *)src
              calledAddress:(SccpAddress *)dst
         applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                   userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
               callingLayer:(UMLayerTCAP *)tcapLayer
                 components:(TCAP_NSARRAY_OF_COMPONENT_PDU *)components
                    options:(NSDictionary *)options
{
    
}

#pragma mark -
#pragma mark Various helper


- (UMASN1Object *)decodeASN1:(UMASN1Object *)params
               operationCode:(int64_t)opcode
               operationType:(UMTCAP_Operation)operation
               operationName:(NSString **)xoperationName
                     context:(id)context
{
    return NULL;
}

- (NSString *)decodeError:(int)err
{
	return [UMLayerGSMMAP decodeError:err];

}

- (void)touch
{
    if(timeoutValue==0)
    {
        timeoutValue=90;
    }
    timeoutDate = [NSDate dateWithTimeIntervalSinceNow:timeoutValue];
}

- (BOOL)isTimedOut
{
    if(timeoutDate == NULL)
    {
        return NO;
    }
    NSDate *now = [NSDate date];
    if([now compare:timeoutDate] == NSOrderedDescending)
    {
        return YES;
    }
    return NO;
}

/* --------------------------------------------------------------------------- */
/*  DIALOG HANDLING */
/* --------------------------------------------------------------------------- */
#pragma mark -
#pragma mark Dialog Handling Methods


-(void) MAP_Open_Req_forUser:(id<UMLayerGSMMAP_UserProtocol>)user
                        tcap:(UMLayerTCAP *)xtcap
                         map:(UMLayerGSMMAP *)xgsmmap
                     variant:(UMTCAP_Variant)xvariant
              callingAddress:(SccpAddress *)src
               calledAddress:(SccpAddress *)dst
          applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                    userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
              userIdentifier:(NSString *)xuserIdentifier
                     options:(NSDictionary *)xoptions
{
    self.mapUser = user;
    self.tcapLayer = xtcap;
    self.gsmmapLayer = xgsmmap;
    self.variant = xvariant;
    self.callingAddress = src;
    self.calledAddress = dst;
    self.applicationContext = appContext;
    self.userInfo = xuserInfo;
    self.options = xoptions;
    self.userIdentifier  = xuserIdentifier;

    UMTCAP_Transaction *t = [tcapLayer getNewOutgoingTransactionForUserDialogId:userDialogId user:self.gsmmapLayer];
    self.tcapTransactionId = t.localTransactionId;

    initiatedOutgoing = YES;
    openEstablished = NO;
    pendingOutgoingComponents = [[UMSynchronizedArray alloc]init];
    pendingIncomingComponents = [[UMSynchronizedArray alloc]init];
    [self touch];
}


-(void) MAP_Open_Ind_forUser:(id<UMLayerGSMMAP_UserProtocol>)user
                        tcap:(UMLayerTCAP *)xtcap
                         map:(UMLayerGSMMAP *)xgsmmap
                     variant:(UMTCAP_Variant)xvariant
              callingAddress:(SccpAddress *)src
               calledAddress:(SccpAddress *)dst
          applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                    userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
               transactionId:(NSString *)localTransactionId
         remoteTransactionId:(NSString *)remoteTransactionId
                     options:(NSDictionary *)xoptions
{
    NSLog(@"MAP_Open_Ind_forUser\n");
    NSLog(@"\tlocalTransactionId: %@\n",localTransactionId);
    NSLog(@"\tremoteTransactionId: %@\n",remoteTransactionId);
    NSLog(@"\tuserDialogId: %@\n",self.userDialogId);
    NSLog(@"\tuserIdentifier: %@\n",self.userIdentifier);

    self.mapUser = user;
    self.tcapLayer = xtcap;
    self.gsmmapLayer = xgsmmap;
    self.variant = xvariant;
    self.callingAddress = src;
    self.calledAddress = dst;
    self.applicationContext = appContext;
    self.userInfo = xuserInfo;
    self.options = xoptions;
    self.tcapTransactionId = localTransactionId;
    if(self.applicationContext)
    {
        dialogResponseRequired = YES;
    }

    initiatedOutgoing = NO;
    openEstablished = YES;
    pendingOutgoingComponents = [[UMSynchronizedArray alloc]init];
    pendingIncomingComponents = [[UMSynchronizedArray alloc]init];

    if(self.userIdentifier==NULL)
    {
        NSString *uid = [user getNewUserIdentifier];
        self.userIdentifier = uid;
        NSLog(@"newUserIdentifier: %@",uid);
    }
    else
    {
        NSLog(@"existingUserIdentifier: %@",self.userIdentifier);

    }
    [user MAP_Open_Ind:self.userIdentifier
                dialog:self.userDialogId
           transaction:localTransactionId
     remoteTransaction:remoteTransactionId
                   map:xgsmmap
               variant:xvariant
        callingAddress:src
         calledAddress:dst
    applicationContext:appContext
              userInfo:xuserInfo
               options:xoptions];
    [self touch];
}

-(void) MAP_Open_Resp_forUser:(id<UMLayerGSMMAP_UserProtocol>)user
                         tcap:(UMLayerTCAP *)xtcap
                          map:(UMLayerGSMMAP *)xgsmmap
                      variant:(UMTCAP_Variant)xvariant
               callingAddress:(SccpAddress *)src
                calledAddress:(SccpAddress *)dst
           applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                     userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
                transactionId:(NSString *)localTransactionId
          remoteTransactionId:(NSString *)remoteTransactionId
                      options:(NSDictionary *)xoptions
{
    NSLog(@"MAP_Open_Resp_forUser\n");
    NSLog(@"\tlocalTransactionId: %@\n",localTransactionId);
    NSLog(@"\tremoteTransactionId: %@\n",remoteTransactionId);
    NSLog(@"\tuserDialogId: %@\n",self.userDialogId);
    NSLog(@"\tuserIdentifier: %@\n",self.userIdentifier);

    self.mapUser = user;
    self.tcapLayer = xtcap;
    self.gsmmapLayer = xgsmmap;
    self.variant = xvariant;
    self.callingAddress = src;
    self.calledAddress = dst;
    self.applicationContext = appContext;
    self.userInfo = xuserInfo;
    self.options = xoptions;
    self.tcapTransactionId = localTransactionId;
    self.tcapRemoteTransactionId = remoteTransactionId;

    openEstablished = YES;
    pendingOutgoingComponents = [[UMSynchronizedArray alloc]init];
    pendingIncomingComponents = [[UMSynchronizedArray alloc]init];
    
    NSString *uid = [user getNewUserIdentifier];
    
    self.userIdentifier = uid;
    
    [user MAP_Open_Resp:uid
                 dialog:self.userDialogId
            transaction:self.tcapTransactionId
       remoteTransaction:self.tcapRemoteTransactionId
                    map:xgsmmap
                variant:xvariant
         callingAddress:src
          calledAddress:dst
     applicationContext:appContext
               userInfo:xuserInfo
                options:xoptions];
    [self touch];
}

- (void)MAP_Delimiter_Req:(NSDictionary *)xoptions
{
    @synchronized (self)
    {
        if(openEstablished==NO)
        {
            if(tcapTransactionId == NULL)
            {
                UMTCAP_Transaction *t = [tcapLayer getNewOutgoingTransactionForUserDialogId:userDialogId user:self.gsmmapLayer];
                tcapTransactionId = t.localTransactionId;
            }
        }
        else
        {
            if(tcapTransactionId == NULL)
            {
                NSLog(@"MAP_Continue_Req: continuing a non existing transation");
                return;
            }
        }

        NSMutableArray *components = [pendingOutgoingComponents mutableCopy];
        pendingOutgoingComponents = [[UMSynchronizedArray alloc] init];

        SccpAddress *src;
        SccpAddress *dst;
        if(initiatedOutgoing)
        {
            src = callingAddress;
            dst = calledAddress;
        }
        else
        {
            src = calledAddress;
            dst = callingAddress;
        }
        if(openEstablished==NO)
        {
            [tcapLayer tcapBeginRequest:tcapTransactionId
                           userDialogId:userDialogId
                                variant:self.variant
                                   user:self
                         callingAddress:src
                          calledAddress:dst
                     applicationContext:applicationContext
                               userInfo:userInfo
                             components:components
                                options:xoptions];
            openEstablished = YES;
            dialogResponseRequired = NO;
        }
        else
        {
            [tcapLayer tcapContinueRequest:tcapTransactionId
                              userDialogId:userDialogId
                                   variant:self.variant
                                      user:self
                            callingAddress:callingAddress
                             calledAddress:calledAddress
                        applicationContext: (dialogResponseRequired ? applicationContext : NULL)
                                  userInfo:NULL
                                components:components
                                   options:xoptions];
            dialogResponseRequired = NO;
        }
    }
    [self touch];
}

-(void) MAP_Close_Req:(NSDictionary *)xoptions
{
    if(dialogIsClosed==YES)
    {
        NSLog(@"MAP_Close_Req: closing a already closed dialog");
        return;
    }
    if(openEstablished==NO)
    {
        NSLog(@"MAP_Close_Req: closing a never opened dialog");
        return;
    }
    if(tcapTransactionId == NULL)
    {
        NSLog(@"MAP_Close_Req: closing a non existing transation");
        return;
    }
    SccpAddress *src;
    SccpAddress *dst;
    if(initiatedOutgoing)
    {
        src = callingAddress;
        dst = calledAddress;
    }
    else
    {
        src = calledAddress;
        dst = callingAddress;
    }
    NSMutableArray *components  = [pendingOutgoingComponents mutableCopy];
    pendingOutgoingComponents   = [[UMSynchronizedArray alloc] init];

    [tcapLayer tcapEndRequest:tcapTransactionId
                 userDialogId:userDialogId
                      variant:self.variant
                         user:self
               callingAddress:src
                calledAddress:dst
           applicationContext: (dialogResponseRequired ? applicationContext : NULL)
                     userInfo:userInfo
                   components:components
                      options:xoptions];
    dialogIsClosed = YES;
    dialogResponseRequired = NO;
    openEstablished = NO;
    [self touch];
}


-(void) MAP_Close_Ind:(NSDictionary *)options
{
    if(openEstablished==NO)
    {
        NSLog(@"MAP_Close_Ind: closing a never opened dialog");
        return;
    }
    if(tcapTransactionId == NULL)
    {
        NSLog(@"MAP_Close_Ind: closing a non existing transation");
        return;
    }
    [mapUser MAP_Close_Ind:userIdentifier options:options];
    dialogIsClosed = YES;
    dialogResponseRequired = NO;
    openEstablished = NO;
    pendingOutgoingComponents   = [[UMSynchronizedArray alloc] init];
    [self touch];
}


-(void) MAP_Delimiter_Ind:(NSDictionary *)options
           callingAddress:(SccpAddress *)src
            calledAddress:(SccpAddress *)dst
       applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                 userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
            transactionId:(NSString *)localTransactionId
      remoteTransactionId:(NSString *)remoteTransactionId
{
    [mapUser MAP_Delimiter_Ind:userIdentifier
                callingAddress:src
                 calledAddress:dst
            applicationContext:appContext
                      userInfo:xuserInfo
                 transactionId:localTransactionId
           remoteTransactionId:remoteTransactionId
                       options:options];
    [self touch];

 }

-(void) MAP_Continue_Ind:(NSDictionary *)options
          callingAddress:(SccpAddress *)src
           calledAddress:(SccpAddress *)dst
      applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
           transactionId:(NSString *)localTransactionId
     remoteTransactionId:(NSString *)remoteTransactionId
{
    [mapUser MAP_Continue_Ind:userIdentifier
               callingAddress:src
                calledAddress:dst
           applicationContext:appContext
                     userInfo:xuserInfo
                transactionId:localTransactionId
          remoteTransactionId:remoteTransactionId
                      options:options];
    [self touch];

}
-(void) MAP_U_Abort_Req:(NSDictionary *)options
{
    NSLog(@"MAP_U_Abort_Req not yet implemented");
    [self touch];
    dialogIsClosed = YES;
    dialogResponseRequired = NO;
    openEstablished = NO;

}

-(void) MAP_P_Abort_Ind:(NSDictionary *)options
         callingAddress:(SccpAddress *)src
          calledAddress:(SccpAddress *)dst
     applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
               userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
          transactionId:(NSString *)localTransactionId
    remoteTransactionId:(NSString *)remoteTransactionId
{
    [mapUser MAP_P_Abort_Ind:self.userIdentifier
              callingAddress:src
               calledAddress:dst
          applicationContext:appContext
                    userInfo:xuserInfo
               transactionId:localTransactionId
         remoteTransactionId:remoteTransactionId
                     options:options];
    [self touch];
    dialogIsClosed = YES;
    dialogResponseRequired = NO;
    openEstablished = NO;
}

-(void) MAP_U_Abort_Ind:(NSDictionary *)options
         callingAddress:(SccpAddress *)src
          calledAddress:(SccpAddress *)dst
     applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
               userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
          transactionId:(NSString *)localTransactionId
    remoteTransactionId:(NSString *)remoteTransactionId
{
    @try
    {
        [mapUser MAP_U_Abort_Ind:self.userIdentifier
                  callingAddress:src
                   calledAddress:dst
              applicationContext:appContext
                        userInfo:xuserInfo
                   transactionId:localTransactionId
             remoteTransactionId:remoteTransactionId
                         options:options];
    }
    @catch(NSException *e)
    {
        NSLog(@"Exception: %@",e);
    }
    [self touch];
    dialogIsClosed = YES;
    dialogResponseRequired = NO;
    openEstablished = NO;
}

-(void) MAP_Notice_Ind:(NSDictionary *)rxoptions
     tcapTransactionId:(NSString *)localTransactionId
                reason:(SCCP_ReturnCause)returnCause
{
    [mapUser MAP_Notice_Ind:userIdentifier
          tcapTransactionId:localTransactionId
                     reason:returnCause
                    options:rxoptions];
    [self touch];
}


/* --------------------------------------------------------------------------- */
/*  COMPONENT HANDLING */
/* --------------------------------------------------------------------------- */
#pragma mark -
#pragma mark component handling: Outgoing Requests
#pragma mark -

- (void) MAP_Invoke_Req:(UMASN1Object *)param
               invokeId:(int64_t)xinvokeId
               linkedId:(int64_t)linkedId
                 opCode:(UMLayerGSMMAP_OpCode *)opcode
                   last:(BOOL)last
                options:(NSDictionary *)options
{
    @synchronized (self)
    {
        if(tcapTransactionId == NULL)
        {
            NSLog(@"MAP_Invoke: adding to a non existing transation");
            return;
        }
        if(xinvokeId == AUTO_ASSIGN_INVOKE_ID)
        {
            xinvokeId = [self nextInvokeId];
        }
        lastInvokeId = xinvokeId;
        
        UMASN1Object *invoke = [tcapLayer tcapInvoke:param
                                             variant:TCAP_VARIANT_DEFAULT
                                            invokeId:xinvokeId
                                            linkedId:linkedId
                                         useLinkedId: ((linkedId == TCAP_UNDEFINED_LINKED_ID) ? NO : YES)
                                         opCodeValue:opcode.operation
                                        opCodeFamily:opcode.family
                                      opCodeNational:opcode.national
                                                last:last];
        [pendingOutgoingComponents addObject:invoke];
    }
    [self touch];
}

- (void) MAP_ReturnResult_Req:(UMASN1Object *)param
                     invokeId:(int64_t)xinvokeId  /* if not used: AUTO_ASSIGN_INVOKE_ID */
                     linkedId:(int64_t)linkedId  /* if not used: TCAP_UNDEFINED_LINKED_ID */
                       opCode:(UMLayerGSMMAP_OpCode *)opcode
                         last:(BOOL)last
                      options:(NSDictionary *)options;
{
    @synchronized (self)
    {
        if(tcapTransactionId == NULL)
        {
            
            UMTCAP_Transaction *t = [tcapLayer getNewOutgoingTransactionForUserDialogId:userDialogId user:self];
            tcapTransactionId = t.localTransactionId;
        }
        if(xinvokeId == AUTO_ASSIGN_INVOKE_ID)
        {
            xinvokeId = [self nextInvokeId];
        }
        lastInvokeId = xinvokeId;

        UMASN1Object *r;
        if(last)
        {
            r =  [tcapLayer tcapResultLastRequest:param
                                          variant:TCAP_VARIANT_DEFAULT
                                         invokeId:xinvokeId
                                         linkedId:linkedId
                                      useLinkedId: ((linkedId == TCAP_UNDEFINED_LINKED_ID) ? NO : YES)
                                      opCodeValue:opcode.operation
                                     opCodeFamily:opcode.family
                                   opCodeNational:opcode.national];
        }
        else
        {
            r =  [tcapLayer tcapResultNotLastRequest:param
                                          variant:TCAP_VARIANT_DEFAULT
                                         invokeId:xinvokeId
                                         linkedId:linkedId
                                      useLinkedId: ((linkedId == TCAP_UNDEFINED_LINKED_ID) ? NO : YES)
                                      opCodeValue:opcode.operation
                                     opCodeFamily:opcode.family
                                   opCodeNational:opcode.national];
        }
        [pendingOutgoingComponents addObject:r];
    }
    [self touch];
}

- (void)MAP_Error_Req:(UMASN1Object *)param
       callingAddress:(SccpAddress *)src
        calledAddress:(SccpAddress *)dst
   applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
             userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
            operation:(int64_t)operation
              options:(NSDictionary *)options
{
    NSLog(@"Missing implementation: MAP_Error_Req");
    [self touch];
}


- (void)MAP_Reject_Req:(UMASN1Object *)param
        callingAddress:(SccpAddress *)src
         calledAddress:(SccpAddress *)dst
    applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
              userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
              invokeId:(int64_t)invokeId
               problem:(UMGSMMAP_asn1 *)problem
               options:(NSDictionary *)options
{
    NSLog(@"Missing implementation: MAP_Reject_Req");
    [self touch];
}

- (void)MAP_ReturnError_Req:(UMASN1Object *)param
                   invokeId:(int64_t)invokeId  /* if not used: AUTO_ASSIGN_INVOKE_ID */
                   linkedId:(int64_t)linkedId  /* if not used: TCAP_UNDEFINED_LINKED_ID */
                     opCode:(UMLayerGSMMAP_OpCode *)opcode
                  errorCode:(int64_t)errorCode
                    options:(NSDictionary *)options
{
    NSLog(@"Missing implementation: MAP_ReturnError_Req");
    [self touch];
}

- (void)MAP_ReturnError_Ind:(UMGSMMAP_asn1 *)params
                     opCode:(UMLayerGSMMAP_OpCode *)opcode
                   invokeId:(int64_t)invokeId
                   linkedId:(int64_t)linkedId
                  errorCode:(int64_t)errorCode
                    options:(NSDictionary *)options
{
    NSLog(@"Missing implementation: MAP_ReturnError_Ind");
    [self touch];
}

- (void)MAP_Reject_Ind:(UMGSMMAP_asn1 *)params
                opCode:(UMLayerGSMMAP_OpCode *)opcode
              invokeId:(int64_t)invokeId
              linkedId:(int64_t)linkedId
             errorCode:(int64_t)errorCode
               options:(NSDictionary *)options
{
    NSLog(@"Missing implementation: MAP_Reject_Ind");
    [self touch];
}

#pragma mark -
#pragma mark component handling: incoming indicatins & requests

- (void)MAP_Invoke_Ind:(UMASN1Object *)params
                opCode:(UMLayerGSMMAP_OpCode *)xopcode
              invokeId:(int64_t)xinvokeId
              linkedId:(int64_t)xlinkedId
                  last:(BOOL)xlast
               options:(NSDictionary *)xoptions
{
    [mapUser MAP_Invoke_Ind:params
                     userId:userIdentifier
                     dialog:userDialogId
                transaction:tcapTransactionId
                     opCode:xopcode
                   invokeId:xinvokeId
                   linkedId:xlinkedId
                       last:xlast
                    options:xoptions];
    [self touch];
}

- (void)MAP_ReturnResult_Resp:(UMGSMMAP_asn1 *)params
                       opCode:(UMLayerGSMMAP_OpCode *)xopcode
                     invokeId:(int64_t)xinvokeId
                     linkedId:(int64_t)xlinkedId
                         last:(BOOL)xlast
                      options:(NSDictionary *)xoptions
{
    [mapUser MAP_ReturnResult_Resp:params
                            userId:userIdentifier
                            dialog:userDialogId
                       transaction:tcapTransactionId
                            opCode:xopcode
                          invokeId:xinvokeId
                          linkedId:xlinkedId
                              last:xlast
                           options:xoptions];
    [self touch];
}

- (void)MAP_ReturnError_Resp:(UMGSMMAP_asn1 *)params
                      opCode:(UMLayerGSMMAP_OpCode *)xopcode
                    invokeId:(int64_t)xinvokeId
                    linkedId:(int64_t)xlinkedId
                   errorCode:(int64_t)xerrorCode
                     options:(NSDictionary *)xoptions
{
    [mapUser MAP_ReturnError_Resp:params
                           userId:userIdentifier
                           dialog:userDialogId
                      transaction:tcapTransactionId
                           opCode:xopcode
                         invokeId:xinvokeId
                         linkedId:xlinkedId
                        errorCode:xerrorCode
                          options:xoptions];
}

- (void)MAP_Reject_Resp:(UMGSMMAP_asn1 *)params
                 opCode:(UMLayerGSMMAP_OpCode *)xopcode
               invokeId:(int64_t)xinvokeId
               linkedId:(int64_t)xlinkedId
              errorCode:(int64_t)xerrorCode
                options:(NSDictionary *)xoptions
{
    [mapUser MAP_Reject_Resp:params
                      userId:userIdentifier
                      dialog:userDialogId
                 transaction:tcapTransactionId
                      opCode:xopcode
                    invokeId:xinvokeId
                    linkedId:xlinkedId
                   errorCode:xerrorCode
                     options:xoptions];
}


- (void)MAP_ProcessComponents:(NSArray *)components
                      options:(NSDictionary *)xoptions
{
    for(UMTCAP_generic_asn1_componentPDU *component in components)
    {
        UMLayerGSMMAP_OpCode *op = [[UMLayerGSMMAP_OpCode alloc]init];
        op.operation = component.operationCode;
        op.family = component.operationCodeFamily;
        op.national = component.operationNational;
        
        switch(component.asn1_tag.tagNumber)
        {
            case TCAP_ITU_COMPONENT_INVOKE:
                [self MAP_Invoke_Ind:component.params
                                opCode:op
                              invokeId:component.invokeId
                              linkedId:component.linkedId
                                  last:component.isLast
                               options:options];
                break;
            case TCAP_ITU_COMPONENT_RETURN_RESULT_LAST:
            {
                UMGSMMAP_asn1 *gasn1 = [[UMGSMMAP_asn1 alloc]initWithASN1Object:component.params context:self];
                [self MAP_ReturnResult_Resp:gasn1
                                      opCode:op
                                    invokeId:component.invokeId
                                    linkedId:component.linkedId
                                        last:YES
                                     options:options];
                break;
            }
            case TCAP_ITU_COMPONENT_RETURN_RESULT_NOT_LAST:
            {
                UMGSMMAP_asn1 *gasn1 = [[UMGSMMAP_asn1 alloc]initWithASN1Object:component.params context:self];
                [self MAP_ReturnResult_Resp:gasn1
                                      opCode:op
                                    invokeId:component.invokeId
                                    linkedId:component.linkedId
                                        last:NO
                                     options:options];
                break;
            }
            case TCAP_ITU_COMPONENT_RETURN_ERROR:
            {
                UMGSMMAP_asn1 *gasn1 = [[UMGSMMAP_asn1 alloc]initWithASN1Object:component.params context:self];
                [self MAP_ReturnError_Resp:gasn1
                                     opCode:op
                                   invokeId:component.invokeId
                                   linkedId:component.linkedId
                                  errorCode:component.errorCode
                                    options:options];
                break;
            }
            case TCAP_ITU_COMPONENT_REJECT:
            {
                UMGSMMAP_asn1 *gasn1 = [[UMGSMMAP_asn1 alloc]initWithASN1Object:component.params context:self];
                [self MAP_Reject_Resp:gasn1
                                opCode:op
                              invokeId:component.invokeId
                              linkedId:component.linkedId
                             errorCode:component.errorCode
                               options:options];
                break;
            }
        }
    }
}





- (void)tcapContinueIndication:(NSString *)userDialogId
             tcapTransactionId:(NSString *)localTransactionId
       tcapRemoteTransactionId:(NSString *)remoteTransactionId
                       variant:(UMTCAP_Variant)var
                callingAddress:(SccpAddress *)src
                 calledAddress:(SccpAddress *)dst
            applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                      userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
                  callingLayer:(UMLayer *)tcapLayer
                    components:(TCAP_NSARRAY_OF_COMPONENT_PDU *)components
                       options:(NSDictionary *)options
{

}

- (void)tcapEndIndication:(NSString *)userDialogId
        tcapTransactionId:(NSString *)localTransactionId
  tcapRemoteTransactionId:(NSString *)remoteTransactionId
                  variant:(UMTCAP_Variant)var
           callingAddress:(SccpAddress *)src
            calledAddress:(SccpAddress *)dst
       applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                 userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
             callingLayer:(UMLayer *)tcapLayer
               components:(TCAP_NSARRAY_OF_COMPONENT_PDU *)components
                  options:(NSDictionary *)options
{

}


- (void)tcapUnidirectionalIndication:(NSString *)userDialogId
                   tcapTransactionId:(NSString *)localTransactionId
             tcapRemoteTransactionId:(NSString *)remoteTransactionId
                             variant:(UMTCAP_Variant)variant
                      callingAddress:(SccpAddress *)src
                       calledAddress:(SccpAddress *)dst
                  applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                            userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
                        callingLayer:(UMLayer *)tcapLayer
                          components:(TCAP_NSARRAY_OF_COMPONENT_PDU *)components
                             options:(NSDictionary *)options
{

}


- (void)tcapNoticeIndication:(NSString *)userDialogId
           tcapTransactionId:(NSString *)localTransactionId
     tcapRemoteTransactionId:(NSString *)remoteTransactionId
                     variant:(UMTCAP_Variant)variant
              callingAddress:(SccpAddress *)src
               calledAddress:(SccpAddress *)dst
          applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                    userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
                callingLayer:(UMLayer *)tcapLayer
                  components:(TCAP_NSARRAY_OF_COMPONENT_PDU *)components
                      reason:(SCCP_ReturnCause)reason
                     options:(NSDictionary *)options
{

}



- (void)tcapPAbortIndication:(NSString *)userDialogId
           tcapTransactionId:(NSString *)localTransactionId
     tcapRemoteTransactionId:(NSString *)remoteTransactionId
                     variant:(UMTCAP_Variant)variant
              callingAddress:(SccpAddress *)src
               calledAddress:(SccpAddress *)dst
          applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                    userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
                callingLayer:(UMLayer *)tcapLayer
                        asn1:(UMASN1Object *)asn1
                     options:(NSDictionary *)options
{
    dialogIsClosed = YES;
    dialogResponseRequired = NO;
    openEstablished = NO;
}


- (void)tcapUAbortIndication:(NSString *)userDialogId
           tcapTransactionId:(NSString *)localTransactionId
     tcapRemoteTransactionId:(NSString *)remoteTransactionId
                     variant:(UMTCAP_Variant)variant
              callingAddress:(SccpAddress *)src
               calledAddress:(SccpAddress *)dst
          applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                    userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
                callingLayer:(UMLayer *)tcapLayer
                        asn1:(UMASN1Object *)asn1
                     options:(NSDictionary *)options
{
    dialogIsClosed = YES;
    dialogResponseRequired = NO;
    openEstablished = NO;
}

- (void)timeOut
{
    [mapUser MAP_P_Abort_Ind:self.userIdentifier
              callingAddress:self.callingAddress
               calledAddress:self.calledAddress
          applicationContext:self.applicationContext
                    userInfo:NULL
               transactionId:self.tcapTransactionId
         remoteTransactionId:self.tcapRemoteTransactionId
                     options:options];
    dialogIsClosed = YES;
    dialogResponseRequired = NO;
    openEstablished = NO;
}

@end