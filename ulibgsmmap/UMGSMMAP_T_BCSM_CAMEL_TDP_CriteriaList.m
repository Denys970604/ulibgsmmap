//
//  UMGSMMAP_  T_BCSM_CAMEL_TDP_CriteriaList .m
//  ulibgsmmap
//
//  © 2016  by Andreas Fink
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import "UMGSMMAP_T_BCSM_CAMEL_TDP_CriteriaList.h"

@implementation UMGSMMAP_T_BCSM_CAMEL_TDP_CriteriaList

@synthesize operationName;
@synthesize sequenceEntries;

- (void) processBeforeEncode
{
	[super processBeforeEncode];
	asn1_tag.isConstructed=YES;
	asn1_list = [[NSMutableArray alloc]init];
	for(id entry in sequenceEntries)
	{
		[asn1_list addObject:entry];
	}
}


- (UMGSMMAP_T_BCSM_CAMEL_TDP_CriteriaList *) processAfterDecodeWithContext:(id)context
{
	int p=0;
	UMASN1Object *o = [self getObjectAtPosition:p++];
	sequenceEntries = [[NSMutableArray alloc]init];
	while(o)
	{
		[sequenceEntries addObject:o];
		o = [self getObjectAtPosition:p++];
	}
	return self;
}

- (NSString *) objectName
{
	return @"  T-BCSM-CAMEL-TDP-CriteriaList ";
}
- (id) objectValue
{
	 return sequenceEntries;
}
- (UMASN1Object<UMGSMMAP_asn1_protocol> *)decodeASN1opcode:(int64_t)opcode
                                             operationType:(UMTCAP_Operation)operation
                                             operationName:(NSString **)xop
                                               withContext:(id)context
{
	return self;
}
@end
