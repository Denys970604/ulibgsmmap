//
//  UMLayerGSMMAP.h
//  ulibgsmmap
//
//  Copyright © 2017 Andreas Fink (andreas@fink.org). All rights reserved.
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import <ulib/ulib.h>
#import <ulibgt/ulibgt.h>
#import <ulibgt/ulibgt.h>
#import <ulibsccp/ulibsccp.h>
#import <ulibtcap/ulibtcap.h>

#import "UMLayerGSMMAP_UserProtocol.h"
#import "UMLayerGSMMAP_ProviderProtocol.h"
#import "UMLayerGSMMAP_Dialog.h"
#import "UMLayerGSMMAPApplicationContextProtocol.h"
 
@class UMLayerGSMMAP_Dialog;

@interface UMLayerGSMMAP : UMLayer<UMTCAP_UserProtocol,UMLayerGSMMAP_ProviderProtocol>
{
    UMLayerTCAP *tcap;
    NSString *address;
    UMSynchronizedArray *operations;
    id<UMLayerGSMMAP_UserProtocol> user;
    UMTimer *houseKeepingTimer;
    UMSynchronizedDictionary *dialogs;
    BOOL _housekeeping_running;
    UMMutex *_dialogIdLock;
    UMAtomicDate *_houseKeepingTimerRun;
    UMTimer *_houseKeepingTimer;
}

@property(readwrite,strong) UMLayerTCAP *tcap;
@property(readwrite,strong) NSString *address;
@property(readwrite,strong) SccpSubSystemNumber *ssn;
@property(readwrite,strong) id<UMLayerGSMMAP_UserProtocol> user;
@property(readwrite,assign,atomic) BOOL housekeeping_running;
@property(readwrite,strong) UMAtomicDate *houseKeepingTimerRun;

-(UMMTP3Variant) variant;

- (void) setConfig:(NSDictionary *)cfg applicationContext:(id<UMLayerGSMMAPApplicationContextProtocol>)appContext;
- (void) startUp;
- (NSString *)status;
- (NSUInteger)dialogsCount;

- (UMASN1Object *)decodeASN1:(UMASN1Object *)params
               operationCode:(int64_t)opcode
               operationType:(UMTCAP_Operation)operation
               operationName:(NSString **)operationName
                     context:(id)context;

- (UMLayerGSMMAP_Dialog *)getNewDialogForUser:(id<UMLayerGSMMAP_UserProtocol>)u withId:(NSString *)dialogId;
- (UMLayerGSMMAP_Dialog *)getNewDialogForUser:(id<UMLayerGSMMAP_UserProtocol>)u;

/* old
- (UMTCAP_generic_asn1_componentPDU *)handleComponent:(UMTCAP_generic_asn1_componentPDU *)component
                                   tcapTransactionId:(NSString *)localTransactionId
                                            dialogId:(NSString *)dialogId
                                             variant:(UMTCAP_Variant)var
                                      callingAddress:(SccpAddress *)src
                                       calledAddress:(SccpAddress *)dst
                                  applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                                             userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
                                             options:(NSDictionary *)options
                                      endTransaction:(BOOL *)doEnd
                                          returnType:(UMGSMMAP_ReturnType *)returnType
                                           errorCode:(int64_t *)errorCode
                                             handler:(id<UMGSMMAP_ComponentHandlerProtocol>)handler;
 */


- (NSString *)decodeError:(int)err;
+ (NSString *)decodeError:(int)err;


-(NSString *) MAP_Open_Req_forUser:(id<UMLayerGSMMAP_UserProtocol>)user
                           variant:(UMTCAP_Variant)variant
                    callingAddress:(SccpAddress *)src
                     calledAddress:(SccpAddress *)dst
                applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                          userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
                    userIdentifier:(NSString *)xuserIdentifier
                           options:(NSDictionary *)options;

-(void) MAP_Delimiter_Req:(NSString *)dialogId
                  options:(NSDictionary *)options;

-(void) MAP_Delimiter_Req:(NSString *)dialogId
                  options:(NSDictionary *)options
                   result:(UMTCAP_asn1_Associate_result *)result
               diagnostic:(UMTCAP_asn1_Associate_source_diagnostic *)result_source_diagnostic;

-(void) MAP_Delimiter_Req:(NSString *)dialogId
           callingAddress:(SccpAddress *)src
            calledAddress:(SccpAddress *)dst
                  options:(NSDictionary *)options
                   result:(UMTCAP_asn1_Associate_result *)result
               diagnostic:(UMTCAP_asn1_Associate_source_diagnostic *)result_source_diagnostic;

- (void)MAP_Close_Req:(NSString *)dialogId
       callingAddress:(SccpAddress *)src
        calledAddress:(SccpAddress *)dst
              options:(NSDictionary *)options
               result:(UMTCAP_asn1_Associate_result *)result
           diagnostic:(UMTCAP_asn1_Associate_source_diagnostic *)result_source_diagnostic;


- (void)MAP_Close_Req:(NSString *)dialogId
              options:(NSDictionary *)options
               result:(UMTCAP_asn1_Associate_result *)result
           diagnostic:(UMTCAP_asn1_Associate_source_diagnostic *)result_source_diagnostic;

- (void)MAP_Close_Req:(NSString *)dialogId
              options:(NSDictionary *)options;

- (void) MAP_Invoke_Req:(UMASN1Object *)param
                 dialog:(NSString *)dialogId
               invokeId:(int64_t)xinvokeId
               linkedId:(int64_t)linkedId
                 opCode:(UMLayerGSMMAP_OpCode *)opcode
                   last:(int64_t)last
                options:(NSDictionary *)options;

- (void) MAP_ReturnResult_Req:(UMASN1Object *)xparam
                       dialog:(NSString *)dialogId
                     invokeId:(int64_t)xinvokeId
                     linkedId:(int64_t)xlinkedId
                       opCode:(UMLayerGSMMAP_OpCode *)xopcode
                         last:(int64_t)xlast
                      options:(NSDictionary *)xoptions;

- (void)MAP_ReturnError_Req:(UMASN1Object *)param
                     dialog:(NSString *)dialogId
                   invokeId:(int64_t)xinvokeId  /* if not used: AUTO_ASSIGN_INVOKE_ID */
                   linkedId:(int64_t)xlinkedId  /* if not used: TCAP_UNDEFINED_LINKED_ID */
                     opCode:(UMLayerGSMMAP_OpCode *)opcode
                  errorCode:(int64_t)errorCode
                    options:(NSDictionary *)options;


/*
-(void)MAP_Delimiter_Ind:(NSString *)userIdentifier
                  dialog:(NSString *)dialogId
          callingAddress:(SccpAddress *)src
           calledAddress:(SccpAddress *)dst
      applicationContext:(UMTCAP_asn1_objectIdentifier *)appContext
                userInfo:(UMTCAP_asn1_userInformation *)xuserInfo
           transactionId:(NSString *)localTransactionId
     remoteTransactionId:(NSString *)remoteTransactionId
                 options:(NSDictionary *)options;
*/
- (UMLayerGSMMAP_Dialog *)dialogById:(NSString *)did;
- (void)housekeeping;

@end

