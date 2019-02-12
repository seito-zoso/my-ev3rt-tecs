unless $initialized
  module EV3RT_TECS
    class Speaker < TECS::TsSpeaker
      @@frequency_hash={
        :c4=> 261.63,  :cs4=>277.18,  :d4=> 293.66,
        :ds4=>311.13,  :e4=> 329.63,  :f4=> 349.23,
        :fs4=>369.99,  :g4=> 392.00,  :gs4=>415.30,
        :a4=> 440.00,  :as4=>466.16,  :b4=> 493.88,
        :c5=> 523.25,  :cs5=>554.37,  :d5=> 587.33,
        :ds5=>622.25,  :e5=> 659.25,  :f5=> 698.46,
        :fs5=>739.99,  :g5=> 783.99,  :gs5=>830.61,
        :a5=> 880.00,  :as5=>932.33,  :b5=> 987.77,
        :c6=> 1046.50, :cs6=>1108.73, :d6=> 1174.66,
        :ds6=>1244.51, :e6=> 1318.51, :f6=> 1396.91,
        :fs6=>1479.98, :g6=> 1567.98, :gs6=>1661.22,
        :a6=> 1760.00, :as6=>1864.66, :b6=> 1975.53,
        :c6=> 1046.50, :cs6=>1108.73, :d6=> 1174.66,
        :ds6=>1244.51, :e6=> 1318.51, :f6=> 1396.91,
        :fs6=>1479.98, :g6=> 1567.98, :gs6=>1661.22,
        :a6=> 1760.00, :as6=>1864.66, :b6=> 1975.53}
      private
      def initialize()
        super "BridgeSpeaker"
      end
      @@instance = self.new

      public
      def self.volume=(vol)
        @@instance.setVolume(vol)
      end
      def self.tone(frequency, duration)
        @@instance.playTone(@@frequency_hash[frequency], duration)
      end
    end
  end
end # unless $initialized
