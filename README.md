# b62
Dead simple lightning fast base 62 (only) encoder based on the [yab62 gem][1] by [Teng Siong Ong][2]. Right now there are only few improvements over yab62:

* Index table modified to 0-9|A-Z|a-z instead of 0-9|a-z|A-Z
* Can encode integers bigger than 839299365868340352
* Slightly faster on some environments

## Overview

Adds a to_b62 function to the Integer class that encodes any integer between 0 and 18446744073709551615 to base 62. The encode function is implemented as a C extension so it's much faster than a plain ruby implementation.

## Install

At this moment I have not pushed the gem to rubygems yet, but you can install it directly from Github just like that:

```shell
gem install git://github.com/planas/b62.git
```

Or add it to your Gemfile as well:

```ruby
gem 'b62', :git => git://github.com/planas/b62.git
```

## Use

```ruby
82310.to_b62
B62.to_b62(2377965395771)
```

[1]:https://github.com/siong1987/yab62
[2]:https://github.com/siong1987/