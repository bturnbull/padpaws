require 'padpawslib'

class PadPaws

  def initialize(pad = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm")
    @codec = PadPawsLib::Codec.new(pad)
  end

  def encode(phrase)
    PadPawsLib.encode(@codec, phrase)
  end

  def decode(phrase)
    PadPawsLib.decode(@codec, phrase)
  end

end
