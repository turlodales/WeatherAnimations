#import <CoreLocation/CoreLocation.h>

@interface City : NSObject
@property (assign,nonatomic) BOOL isDay;   
- (id)updateTime;
@end

/* Weathe background */

@interface WUIWeatherCondition : NSObject
-(City *)city;
-(void)pause;
-(void)resume;
-(void)setCondition:(long long)arg1;
-(double)alpha;
-(void)setAlpha:(double)arg1 ;
@end;

@interface WUIDynamicWeatherBackground : UIView
-(void)setCity:(id)arg1 ;
-(WUIWeatherCondition *)condition;
@end

@interface WUIWeatherConditionBackgroundView : UIView
  -(id)initWithFrame:(CGRect)arg1 ;
  -(WUIDynamicWeatherBackground *)background;
  -(void)prepareToSuspend;
-(void)prepareToResume;
@end;

@interface WeatherPreferences
+ (id)sharedPreferences;
- (id)localWeatherCity;
@end


/* other weather */

@interface WeatherLocationManager : NSObject
+(id)sharedWeatherLocationManager;
-(BOOL)locationTrackingIsReady;
-(void)setLocationTrackingReady:(BOOL)arg1 activelyTracking:(BOOL)arg2 watchKitExtension:(id)arg3;
-(void)setLocationTrackingActive:(BOOL)arg1;
-(CLLocation*)location;
-(void)setDelegate:(id)arg1;
-(void)forceLocationUpdate;
@end

@interface WACurrentForecast
@property (assign,nonatomic) long long conditionCode;
@end

@interface WAForecastModel : NSObject
@property (nonatomic,retain) City * city;
@property (nonatomic,retain) WACurrentForecast * currentConditions;
@end

@interface WATodayModel
+(id)autoupdatingLocationModelWithPreferences:(id)arg1 effectiveBundleIdentifier:(id)arg2 ;
-(BOOL)executeModelUpdateWithCompletion:(/*^block*/id)arg1 ;
@property (nonatomic,retain) WAForecastModel * forecastModel;
-(id)location;
@end


@interface WATodayAutoupdatingLocationModel : WATodayModel
-(WAForecastModel *)forecastModel;
-(void)setIsLocationTrackingEnabled:(BOOL)arg1;
-(void)setLocationServicesActive:(BOOL)arg1;
@end
