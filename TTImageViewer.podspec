Pod::Spec.new do |s|
	s.name				= 'TTImageViewer'
	s.version			= '0.2'
	s.summary			= 'Image viewer for Thumbtack apps. Originally based on github.com/u10int/URBMediaFocusViewController.'
	s.homepage		= 'https://github.com/thumbtack/TTImageViewer'
	s.author = {
		'Ian Leitch' => 'ian@carbonfive.com'
	}
	s.source = {
		:git	=> 'https://github.com/thumbtack/TTImageViewer.git',
		:tag	=> s.version.to_s
	}
	s.platform			= :ios, '7.0'
	s.license			= { :type => 'MIT', :file => 'LICENSE' }
	s.requires_arc		= true
	s.source_files		= 'TTImageViewer/TTImageViewerController.{h,m}'
	s.header_mappings_dir = 'TTImageViewer'
	s.frameworks		= 'UIKit', 'Foundation', 'CoreGraphics', 'QuartzCore', 'AssetsLibrary'
	s.ios.deployment_target = '7.0'
end
