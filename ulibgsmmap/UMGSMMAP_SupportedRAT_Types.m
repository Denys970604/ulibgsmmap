//
//  UMGSMMAP_SupportedRAT_Types.m
//  ulibgsmmap
//
//  Created by Andreas Fink on 05.03.18.
//  Copyright © 2018 Andreas Fink (andreas@fink.org). All rights reserved.
//

#import "UMGSMMAP_SupportedRAT_Types.h"

@implementation UMGSMMAP_SupportedRAT_Types

- (UMGSMMAP_SupportedRAT_Types *)initWithString:(NSString *)str
{
    self = [super init];
    if(self)
    {
        NSCharacterSet *whitespace  = [UMObject whitespaceAndNewlineCharacterSet];
        
        NSArray *array = [str componentsSeparatedByString:@","];
        for(NSString *component in array)
        {
            NSString *s = [component stringByTrimmingCharactersInSet:whitespace];
            if([s isEqualToString:@"0"]|| [s isEqualToString:@"utran"])
            {
                [self setBit:0];
            }
            if([s isEqualToString:@"1"]|| [s isEqualToString:@"geran"])
            {
                [self setBit:1];
            }
            if([s isEqualToString:@"2"]|| [s isEqualToString:@"gan"])
            {
                [self setBit:2];
            }
            if([s isEqualToString:@"3"]|| [s isEqualToString:@"i-hspa-evolution"])
            {
                [self setBit:3];
            }
            if([s isEqualToString:@"4"] || [s isEqualToString:@"e-utran"])
            {
                [self setBit:4];
            }
            if([s isEqualToString:@"5"] || [s isEqualToString:@"nb-iot"])
            {
                [self setBit:5];
            }
        }
    }
    return self;
}

@end
