//
//  UMGSMMAP_UtranPositioningDataInfo.m
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import "UMGSMMAP_UtranPositioningDataInfo.h"

@implementation UMGSMMAP_UtranPositioningDataInfo

@synthesize operationName;

- (NSString *) objectName
{
	return @"UMGSMMAP_UtranPositioningDataInfo";
}

- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context
{
	return self;
}
@end
