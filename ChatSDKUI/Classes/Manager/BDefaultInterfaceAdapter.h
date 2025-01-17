//
//  BDefaultInterfaceAdapter.h
//  Pods
//
//  Created by Benjamin Smiley-andrews on 14/09/2016.
//
//

#import <Foundation/Foundation.h>
#import <ChatSDK/PInterfaceAdapter.h>

#define bColorMessageLink @"bColorMessageLink"

// Providers
#define bMessageSectionDateProvider @"BMessageSectionDateProvider"


@class BPrivateThreadsViewController;
@class BPublicThreadsViewController;
@class BFlaggedMessagesViewController;
@class BContactsViewController;
@class BProfilePicturesViewController;
@class BFriendsListViewController;
@class BChatViewController;
@class BSearchViewController;
@class BLocalNotificationHandler;
@class BDetailedEditProfileTableViewController;

@protocol PThread;
@protocol PUser;

@interface BDefaultInterfaceAdapter : NSObject<PInterfaceAdapter> {
    id<PChatOptionsHandler> _chatOptionsHandler;
    NSMutableArray * _additionalChatOptions;
    NSMutableArray * _additionalTabBarViewControllers;
    NSMutableDictionary * _additionalSearchViewControllers;
    NSMutableDictionary * _providers;
    NSMutableArray * _settingsSections;
    NSMutableDictionary * _messageCellTypes;
}

@property (nonatomic, readwrite) UIViewController * privateThreadsViewController;
@property (nonatomic, readwrite) UIViewController * publicThreadsViewController;
@property (nonatomic, readwrite) UIViewController * editThreadViewController;
@property (nonatomic, readwrite) UIViewController * flaggedMessagesViewController;
@property (nonatomic, readwrite) ModerationProvider moderationViewController;
@property (nonatomic, readwrite) UIViewController * contactsViewController;
@property (nonatomic, readwrite) UIViewController * mainViewController;
@property (nonatomic, readwrite) UIViewController * (^searchViewController)(NSArray * usersToExclude, void(^usersAdded)(NSArray * users));
@property (nonatomic, readwrite) UIViewController * (^searchIndexViewController)(NSArray * indexes, void(^callback)(NSArray *));
@property (nonatomic, readwrite) BFriendsListViewController * (^friendsListViewController)(NSArray * usersToExclude, void(^onComplete)(NSArray * users, NSString * groupName));
@property (nonatomic, readwrite) UserProvider profileViewController;
@property (nonatomic, readwrite) UserProvider profileOptionsViewController;
@property (nonatomic, readwrite) BDetailedEditProfileTableViewController * editProfileViewController;

@property (nonatomic, readwrite) UserProvider profilePicturesViewController;
@property (nonatomic, readwrite) UIViewController * termsOfServiceViewController;
@property (nonatomic, readwrite) ChatProvider chatViewController;
@property (nonatomic, readwrite) UIViewController * imageViewController;
@property (nonatomic, readwrite) UIViewController * locationViewController;
@property (nonatomic, readwrite) UIViewController * settingsViewController;
@property (nonatomic, readwrite) UIViewController * (^usersViewController)(id<PThread> thread, UINavigationController * parent);
@property (nonatomic, readwrite) UIViewController<PSplashScreenViewController> * splashScreenViewController;
@property (nonatomic, readwrite) UIViewController * loginViewController;
@property (nonatomic, readwrite) BOOL(^showLocalNotification)(id<PThread> thread);

@end
