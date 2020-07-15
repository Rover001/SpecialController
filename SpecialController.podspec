
Pod::Spec.new do |spec|
  spec.name         = "SpecialController"
  spec.version      = "0.0.3"
  spec.summary      = "SpecialController"
  spec.homepage     = "https://github.com/Rover001/SpecialController.git"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "Rover001" => "zengyun6666@163.com" }
  spec.platform     = :ios, "11.0"
  spec.ios.deployment_target = "11.0"
  spec.source       = { :git => "https://github.com/Rover001/SpecialController.git", :tag => "#{spec.version}" }
  spec.requires_arc = true
  spec.ios.vendored_frameworks  = "SpecialController.framework"
  spec.resources = "Resources/*"
    
end
