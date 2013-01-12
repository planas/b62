Gem::Specification.new do |s|
  s.name          = 'b62'
  s.version       = '1.0.0'
  s.date          = '2013-01-12'
  s.summary       = 'Dead simple lightning fast base 62 encoder.'
  s.description   = <<-EOF
   Adds a to_b62 function to the Integer class that encodes 
   any integer between 0 and 18446744073709551615 to base 62.
   The encode function is implemented as a C extension so it's
   much faster than a plain ruby implementation.
   EOF
  s.authors       = ["Adrià Planas"]
  s.email         = ['adriaplanas@liquidcodeworks.com']
  s.homepage      = 'https://github.com/planas/b62'
  s.files         = Dir.glob('lib/**/*.rb') + Dir.glob('ext/**/*.{c,h,rb}')
  s.extensions    = ['ext/b62/extconf.rb']
end