//
//  UMGSMMAP_Delimiter_Req_Task.h
//  ulibgsmmap
//
//  Created by Andreas Fink on 07.12.17.
//  Copyright © 2017 Andreas Fink (andreas@fink.org). All rights reserved.
//

#import <ulibtcap/ulibtcap.h>
#import "UMGSMMAP_DialogIdentifier.h"
#import "UMGSMMAP_UserIdentifier.h"

@class UMLayerGSMMAP;


@interface UMGSMMAP_Delimiter_Req_Task : UMLayerTask

{
    UMLayerGSMMAP *_instance;
    UMGSMMAP_DialogIdentifier *_dialogId;
    SccpAddress *_callingAddress;
    SccpAddress *_calledAddress;
    NSDictionary *_options;
    UMTCAP_asn1_Associate_result *_result;
    UMTCAP_asn1_Associate_source_diagnostic *_result_source_diagnostic;
}

-(UMGSMMAP_Delimiter_Req_Task *)initWithInstance:(UMLayerGSMMAP *)instance
                                          dialog:(UMGSMMAP_DialogIdentifier *)dialogId
                                  callingAddress:(SccpAddress *)src
                                   calledAddress:(SccpAddress *)dst
                                         options:(NSDictionary *)options
                                          result:(UMTCAP_asn1_Associate_result *)result
                                      diagnostic:(UMTCAP_asn1_Associate_source_diagnostic *)result_source_diagnostic;

- (void)main;

@end

