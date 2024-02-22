import { useState } from 'react';
import './App.css';
import logo from './assets/logo.png';
import arrowDown from './assets/arrow.png';
import smallCircleTopLeft from './assets/smallGradientCircleTopLeft.png';
import gradientCircleTopLeft from './assets/gradientCircleTopLeft.png';
import middleRightCircleGradient from './assets/middleRightCircleGradient.png';
import astronaut from './assets/astronaut.png';
import star from './assets/star.png';
import vectorBackground from './assets/vectorBackground.png';
import astronomyIcon from './assets/astronomyIcon.png';
import higgsFieldIcon from './assets/higgsFieldIcon.png';
import universeIcon from './assets/universeIcon.png';
import circleGradientLeft from './assets/circleGradientLeft.png';
import circleGradientRight from './assets/circleGradientRight.png';
import higgsPreview from './assets/higgsBosonPreview.png';
import naturePreview from './assets/naturePreview.png';
 
function App() {
  return (
    <div className="bg-[#080310] min-h-screen w-screen overflow-x-hidden">
      <div>
        <div className="overflow-x-hidden">
          <img
            src={smallCircleTopLeft}
            alt="Background gradient"
            className="top-0 left-0 absolute select-none"
          />
          <img
            src={gradientCircleTopLeft}
            alt="Background gradient"
            className="top-0 absolute select-none"
          />
        </div>

        <div className="flex items-center text-white cursor-pointer">
          <img
            src={logo}
            alt="Spacio's logo"
            className="w-16 h-auto select-none z-0 ml-1"
          />
          <h1 className="ml-3 font-bold z-0 text-2xl">Spacio</h1>
        </div>

        <div className="text-center my-40 mt-60 text-white">
          <h1 className="text-[8vw] font-bold z-0 relative">SPACIO</h1>
          <div className="flex justify-center">
            <img
              src={arrowDown}
              alt="Arrow down"
              className="select-none cursor-pointer object-center mx-auto mt-20 scale-75"
            />
          </div>
        </div>

        <div className="flex text-white mt-96">
          <div className="ml-48 z-0">
            <h1 className="text-[3.3vw] font-extralight z-0 mb-20">
              About{" "}
              <span className="font-semibold" style={{ color: "#81689D" }}>
                Spacio
              </span>
            </h1>

            <p className="text-[2.4vw] font-light z-0 max-w-2xl">
              A one-of-a-kind educational application that offers endless
              excitement and knowledge for your brain. Download it and challenge
              yourself to learn as much as possible!
            </p>
          </div>

          <img
            src={astronaut}
            alt="Astronaut's image"
            className="w-6/12 h-2/4 select-none z-10"
          />

          <div>
            <img
              src={star}
              alt="Stars"
              className="-rotate-45 absolute right-[45%] select-none scale-75"
            />
            <img
              src={star}
              alt="Stars"
              className="rotate-[120deg] absolute right-1/2 top-[140vh] scale-[0.8] select-none"
            />
            <img
              src={star}
              alt="Stars"
              className="rotate-[15deg] absolute right-[20%] top-[160vh] select-none z-10"
            />
            <img
              src={star}
              alt="Stars"
              className="-rotate-[27deg] absolute right-[5%] select-none z-10"
            />
          </div>
        </div>

        <div className="flex text-white text-[2.5vw] mt-24">
          <h1 className="ml-48 font-extralight z-10 mt-5">
            You can download our app from here
          </h1>
          <button className="z-10 ring-4 bg-[#81689D] rounded-3xl p-6 ml-12 mb-5 ring-[#81689D] font-semibold shadow-lg shadow-[#81689D] cursor-pointer">
            Download
          </button>
        </div>
        <img
          src={vectorBackground}
          alt="Background"
          className="absolute select-none"
        />

        <div>
          <img
            src={middleRightCircleGradient}
            alt="Background gradient"
            className="right-[-1rem] absolute top-[70vh] select-none"
          />
          <h1 className="text-white z-10 text-[2.5vw] max-g:text-3xl font-thin mt-[20%] mb-[15%] relative inset-0 flex items-center justify-center">
            Enhance your skills in these areas.
          </h1>

          <div>
            <div className="left-0 top-0 w-[25vw] h-px bg-white"></div>
            <div className="absolute inset-0 flex items-center justify-center mt-[265vh] text-[1.8vw]">
              <div
                id="here"
                className="flex flex-row items-center space-x-28 font-light z-10"
              >
                <div className="relative">
                  <img
                    src={astronomyIcon}
                    className="relative w-[8vw] h-auto select-none"
                    alt="astronomy's Icon"
                  />
                  <p className="text-white text-center">Astronomy</p>
                </div>
                <div className="relative">
                  <img
                    src={higgsFieldIcon}
                    className="relative w-[8vw] h-auto select-none"
                    alt="Higgs field's icon"
                  />
                  <p className="text-white text-center">
                    Higgs field
                  </p>
                </div>
                <div className="relative">
                  <img
                    src={universeIcon}
                    className="relative w-[8vw] h-auto select-none"
                    alt="Universe's icon"
                  />
                  <p className="text-white text-center">Universe</p>
                </div>
              </div>
            </div>
          </div>

          <div className="absolute -right-0 top-[120] w-[25vw] h-px bg-white"></div>
        </div>
        <img
          src={circleGradientLeft}
          alt="Background decoration"
          className="absolute top-[200vh] left-0 select-none"
        />
        <img
          src={circleGradientRight}
          alt="Background decoration"
          className="absolute top-[220vh] right-0 select-none"
        />

        <div class="flex items-center justify-center h-screen mt-36">
          <div class="space-y-24 text-[3.5vw] z-10 relative font-thin">
            <div class="flex flex-row">
              <p class="text-white mt-[10%] mr-[10vw]">Dynamic Learning.</p>
              <img src={higgsPreview} alt="Higgs Boson preview" className='w-auto h-[20vw]' />
            </div>

            <div class="flex flex-row">
              <p class="text-white">Skill assesment.</p>
              <img src={star} alt="Star" />
            </div>

            <div class="flex flex-row">
              <p class="text-white">Fun experience.</p>
              <img src={star} alt="Star" />
            </div>
          </div>
        </div>
      </div>
    </div>
  );
}
 
export default App;