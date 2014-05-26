/*
 * (c) Copyright 2000-2011 spring saarlouis
 * All Rights Reserved.
 * 
 * contact info@spring.de for more information
 */



/**
 * Static tags of the application status
 */
extern NSString *const SPRING_VAR_ACTION;
extern NSString *const SPRING_APP_STARTED;
extern NSString *const SPRING_APP_FOREGROUND;
extern NSString *const SPRING_APP_BACKGROUND;
extern NSString *const SPRING_APP_CLOSED;


@interface Spring : NSObject {
}
    
/** Enable or disable usage tracking. (default: true) */
@property(nonatomic, getter=isTracking) BOOL tracking;
    
/**
 * When set to true (default:false) the library logs the internal actions.
 * Each error is logged without checking this property.
 */
@property(nonatomic) BOOL debug;

/**
 * Enable or disable offline mode. It will be configured in the release process. 
 * Please refer to main page for more info about offlineMode
 */
@property(nonatomic) BOOL offlineMode;
/**
 * Internally it sends http requests to the measurement system.
 * This property sets a timeout for that purpose.
 */
@property(assign) NSTimeInterval timeout;

/**
 * return the instance of spring lib, in id type
 * Initialization of the spring library, with a site name and an application name
 * @warning
 *   The site name and the application name should be provided accrodingly
 */
- (id)initWithSiteAndApplication:(NSString *)theSite application:(NSString *)theApplication;

/**
 * Commit gathered data to server when application status changes.
 * Initialization of the spring library, with a site name and an application name
 * @throws An exception is thrown when connection problem occurs.
*/
- (void)commit:(NSDictionary *)theDictionary;
	
@end


/**
 * @mainpage
 * <h3>Version 1.6.0</h3>
 * <table>
 * <tr>
 * <th>Changes</th><th>Attribute</th><th>Description</th>
 * </tr>
 <tr>
 <td>
 PanelApp Switch: Url Scheme</td>
 <td>
 New Feature</td>
 <td>
 <p>
 Since Spring 1.6.0, the lib will try to call a corresponding PanelApp (by URL Scheme, happens in the initializaiton phase, only called once if ifv is not changed since last lauch), and send ifv (identifier_for_vendor) and related parameters to the PanelApp. This mechanism is designed for identifying each single device owned by the end user. (ifv is unique for each vendor, but not globally)</p>
 <p>
 For adapting this mechanism, the clients of Spring lib has to implement their own PanelApp and also import Spring/SpringStreams lib into it.</p>
 </td>
 </tr>
 <tr>
 <td>
 arm64 bits support</td>
 <td>
 New Feature</td>
 <td>
 <p>
 Since Spring 1.6.0, the lib will support arm64 bit&nbsp;architecture, Spring lib will be applicable for latest iOS devices.</p>
 </td>
 </tr>
 <tr>
 <td>
 Customized special fields</td>
 <td>
 Changes</td>
 <td>
 <p>
 More customized parameteres/special fields are inserted into measuring http request, applied to our lib accordingly based on the different domains.</p>
 </td>
 </tr>
 * </table>

 * <h3>Version 1.5.2</h3>
 * <table>
 * <tr>
 * <th></th><th>Attribute</th><th>Description</th>
 * </tr>
 * <tr>
 * <td>Identifier of Device</td><td>New Feature</td><td> The identifier of the device would be advertisement id + identifier_for_vendor(https://developer.apple.com/library/ios/documentation/uikit/reference/UIDevice_Class/Reference/UIDevice.html#//apple_ref/occ/instp/UIDevice/identifierForVendor) if your application contains video advertisement, otherwise the identifier of the device would be only identifier for vendor. This change responses to the modification of Apple Developers' Policy, advertisement ids are not accepted if no video adversements are involved in the application. </td>
 * </tr>
 * <tr>
 * <td>lib Management</td><td>Change</td><td>PLEASE NOTICE: We have intergrated our spring sensor libraries for our clients to one, and this universal lib is applicable for all our clients. Your customized configurations are applied based on different domain, so it does not influence the functionalities of the library. This change affects some clients who are using old Spring library, please change your header file Spring*.h (your company indentifier), to Spring.h</td>
 * </tr>
 * </table>
 * <h3>Version 1.5.1</h3>
 * <table>
 * <tr>
 * <th></th><th>Attribute</th><th>Description</th>
 * </tr>
 * <tr>
 * <td>Advertising-Framework</td><td>Improvement</td><td>Advertising-Framework is linked as optional for the compatibility purpose of iOS versions earlier than iOS 6</td>
 * </table>
 * <h3>Version 1.5.0</h3>
 * <table>
 * <tr>
 * <th></th><th>Attribute</th><th>Description</th>
 * </tr>
 * <tr>
 * <td>OfflineMode</td><td>New Feature</td><td>If the app is configured to offlineMode, spring library would hold all requests in a local buffer and send them until the device goes back online.
 *  Spring lib checks the internet connection regularly by using a Timer and send the data as soon as possible. Please notice:\n
 * -# Old requests would be droped if too many requests pump into local buffer for the limitation in buffer size. The default buffer size is 1000. The data will be stored in a local file, so we would not lose the requests even if the applicaiton terminated.
 * -# Spring lib tries to send the requests in a fixed rate, 10 seconds by default, and sends them if device is online. This is achieved by using Apple NSTimer.
 \n\n
 * This mode can be switched on and off by using public API. @see Spring.offlineMode</td>
 * </tr>
 * </table>
 */
