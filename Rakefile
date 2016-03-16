require 'rake/extensiontask'

Rake::ExtensionTask.new('ruby_lemon')

require 'rake/testtask'

Rake::TestTask.new do |t|
  t.libs << "test"
  t.test_files = FileList['test/test*.rb']
  t.verbose = true
end