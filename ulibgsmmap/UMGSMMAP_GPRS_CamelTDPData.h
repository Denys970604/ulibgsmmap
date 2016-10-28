//
//  UMGSMMAP_GPRS_CamelTDPData.h
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import <ulibasn1/ulibasn1.h>
#import "UMGSMMAP_asn1_protocol.h"

#import "UMGSMMAP_GPRS_TriggerDetectionPoint.h"
#import "UMGSMMAP_ServiceKey.h"
#import "UMGSMMAP_ISDN_AddressString.h"
#import "UMGSMMAP_DefaultGPRS_Handling.h"
#import "UMGSMMAP_ExtensionContainer.h"

@interface UMGSMMAP_GPRS_CamelTDPData : UMASN1Sequence<UMGSMMAP_asn1_protocol>
{
	NSString *operationName;
	UMGSMMAP_GPRS_TriggerDetectionPoint *gprs_TriggerDetectionPoint;
	UMGSMMAP_ServiceKey *serviceKey;
	UMGSMMAP_ISDN_AddressString *gsmSCF_Address;
	UMGSMMAP_DefaultGPRS_Handling *defaultSessionHandling;
	UMGSMMAP_ExtensionContainer *extensionContainer;
}
@property(readwrite,strong)    NSString *operationName;

@property(readwrite,strong)	UMGSMMAP_GPRS_TriggerDetectionPoint *gprs_TriggerDetectionPoint;
@property(readwrite,strong)	UMGSMMAP_ServiceKey *serviceKey;
@property(readwrite,strong)	UMGSMMAP_ISDN_AddressString *gsmSCF_Address;
@property(readwrite,strong)	UMGSMMAP_DefaultGPRS_Handling *defaultSessionHandling;
@property(readwrite,strong)	UMGSMMAP_ExtensionContainer *extensionContainer;


- (void)processBeforeEncode;
- (UMGSMMAP_GPRS_CamelTDPData *)processAfterDecodeWithContext:(id)context;
- (NSString *)objectName;
- (id)objectValue;
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context;

@end