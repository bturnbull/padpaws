require File.join(File.dirname(__FILE__), '..', 'lib', 'padpaws')

describe PadPaws do

  before :each do
    @padpaws = PadPaws.new
  end

  it 'should properly encode' do
    @padpaws.encode('Hello, World!').should == 'Uryyb, Jbeyq!'
  end

  it 'should properly decode' do
    @padpaws.decode('Uryyb, Jbeyq!').should == 'Hello, World!'
  end

end
