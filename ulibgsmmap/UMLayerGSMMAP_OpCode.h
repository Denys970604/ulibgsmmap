//
//  UMLayerGSMMAP_OpCode.h
//  ulibgsmmap
//
//  Copyright © 2017 Andreas Fink (andreas@fink.org). All rights reserved.
//
// This source is dual licensed either under the GNU GENERAL PUBLIC LICENSE
// Version 3 from 29 June 2007 and other commercial licenses available by
// the author.
//
#import <ulib/ulib.h>
#import <ulibasn1/ulibasn1.h>

@interface UMLayerGSMMAP_OpCode : UMObject
{
    int64_t operation;
    int64_t family;
    UMASN1ObjectIdentifier *_globalOperation;
    BOOL national;
}

@property (readwrite,assign) int64_t operation;
@property (readwrite,assign) int64_t family;
@property (readwrite,assign) BOOL national;
@property (readwrite,strong) UMASN1ObjectIdentifier *globalOperation;

- (UMLayerGSMMAP_OpCode *)initWithOperationCode:(int64_t)op;
- (UMLayerGSMMAP_OpCode *)initWithGlobalOperationCode:(int64_t)op;
- (NSString *)description;

@end
