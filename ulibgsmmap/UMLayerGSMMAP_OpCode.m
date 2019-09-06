//
//  UMLayerGSMMAP_OpCode.m
//  ulibgsmmap
//
//  Copyright © 2017 Andreas Fink (andreas@fink.org). All rights reserved.
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import "UMLayerGSMMAP_OpCode.h"

@implementation UMLayerGSMMAP_OpCode

@synthesize operation;
@synthesize family;
@synthesize national;

- (UMLayerGSMMAP_OpCode *)initWithOperationCode:(int64_t)op
{
    self = [super init];
    if(self)
    {
        operation = op;
    }
    return self;
}

- (UMLayerGSMMAP_OpCode *)initWithGlobalOperationCode:(int64_t)op
{
    self = [super init];
    if(self)
    {
        operation = op;
        family = UMTCAP_itu_operationCodeFamily_Global;
    }
    return self;
}

- (NSString *)description
{
    if((family == 0) && (national == NO))
    {
        return [NSString stringWithFormat:@"%ld",(long)operation];
    }
    return [NSString stringWithFormat:@"{ operation: %ld, family: %ld, national: %@ }",
            (long)operation,
            (long)family,
            (national ? @"YES" : @"NO")];
}
@end
