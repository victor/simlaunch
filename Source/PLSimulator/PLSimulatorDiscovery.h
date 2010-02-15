/*
 * Author: Landon Fuller <landonf@plausiblelabs.com>
 *
 * Copyright (c) 2010 Plausible Labs Cooperative, Inc.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#import <Cocoa/Cocoa.h>

#import "PLSimulatorPlatform.h"
#import "rpm-vercomp.h"

@class PLSimulatorDiscovery;

/**
 * The PLSimulatorDiscoveryDelegate defines the methods used to receive provides simulator discovery
 * results from a PLSimulatorDiscoveryDelegate object. 
 */
@protocol PLSimulatorDiscoveryDelegate <NSObject>

/**
 * Called by the PLSimulatorDiscovery instance upon query completion.
 *
 * @param discovery The sender.
 * @param platforms PLSimulatorPlatform instances that matched the query, or an empty array of no matches were found.
 */
- (void) simulatorDiscovery: (PLSimulatorDiscovery *) discovery didFindMatchingSimulatorPlatforms: (NSArray *) platforms;

@end

@interface PLSimulatorDiscovery : NSObject {
@private
    /** Requested minimum version. */
    NSString *_version;

    /** Requested device families. See \ref plsimulator_device_family Device Family Constants */
    NSSet *_deviceFamilies;

    /** Spotlight query used to find the SDK(s) */
    NSMetadataQuery *_query;

    /** Set to YES if the query is running */
    BOOL _running;

    /** Delegate */
    id<PLSimulatorDiscoveryDelegate> _delegate;
}

- (id) initWithMinimumVersion: (NSString *) version deviceFamilies: (NSSet *) deviceFamilies;

- (void) startQuery;

/** Search delegate. */
@property(assign) id<PLSimulatorDiscoveryDelegate> delegate;

@end