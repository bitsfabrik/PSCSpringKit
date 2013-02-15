# PSCSpringKit

Easy to use API for Spring Mobile App Sensor (aka ÖWA Mobile App Sensor)

## Integration

### 1. Create the shared SpringKitManager object:

The hitTestClasses-Array defines on which classes and subclasses a count should performed when an object of them is tapped. So in the most cases it's enough to let PSCSpringKitManager react on UIControl and subclasses.

Best time to create the PSCSpringKitManager is in application:didFinishLaunchingWithOptions:

```objective-c
NSArray *hitTestClasses = @[
    [UIControl class],
    [MyViewToCheckForTouches class]
];
[PSCSpringKitManager createSharedSpringKitManagerWithSite:@"mySite" application:@"myApplication" path:@"myPath" hitTestClasses:hitTestClasses];
```

### 2. Change UIWindow to PSCSpringKitWindow

The PSCSpringKitWindow class overrides the hitTest:withEvent: function to check all touches so you need to change your UIWindows to PSCSpringKitWindow. For example you can do that in application:didFinishLaunchingWithOptions:

```objective-c 
self.window = [[PSCSpringKitWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
// do any additional window initialization (e.g. setRootViewController)
[self.window makeKeyAndVisible];
```

## Add to your project

1. Add PSCSpringKit.xcodeproj as subproject.
2. Add PSCSpringKit's root folder to your project's header search paths.
3. Add PSCSpringKit to your Target's dependencies (Target >> Build Phases >> Target Dependencies).
4. Add PSCSpringKit to your Target's linked frameworks (Target >> Summary >> Linked Frameworks and Libraries).
5. Import "PSCSpringKit.h" either in Prefix.pch or seperatly in any file you use it.

## Spring Mobile App Sensor

The static library "spring-appsensor-fat-oewa.a" (Version 1.1.2) included is created by [spring GmbH & Co KG](http://www.spring.de). For more information about the library take a look at [Spring's Project Website](https://confluence.spring.de/pages/viewpage.action?pageId=26902687).

## Credits

PSCSpringKit was created by [Manfred Scheiner](https://github.com/scheinem/) ([@scheinem](http://twitter.com/scheinem) - [scheinem.com](http://scheinem.com)).

## License

PSCSpringKit is available under the MIT license. See the LICENSE file for more info.
For usage without attribution contact [PocketScience GmbH](mailto:office@procketscience.com).