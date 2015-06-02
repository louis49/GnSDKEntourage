Pod::Spec.new do |s|
s.name     = 'GnSDKEntourage'
s.version  = '1.0'
s.platform = :ios, '7.0'
s.summary  = 'socket.io iOS devices.'
s.author   = { 'DESNOS Benoît' => 'desnos.benoit@gmail.com' }
s.vendored_frameworks = 'GnSDKEntourage.framework'
s.public_header_files = 'GnSDKEntourage.framework/Headers/*.h'
s.requires_arc = true
s.frameworks = 'AudioToolbox', 'AVFoundation', 'Foundation', 'CoreMedia'
s.xcconfig = {
	    'OTHER_LDFLAGS' => '-lstdc++',
	    'CLANG_CXX_LIBRARY' => 'libstdc++'
	  }
end