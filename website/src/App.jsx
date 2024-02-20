import { useState } from 'react';
import './App.css';
import logo from './assets/logo.png';
import arrowDown from './assets/arrow.png';
import smallCircleTopLeft from './assets/smallGradientCircleTopLeft.png';
import gradientCircleTopLeft from './assets/gradientCircleTopLeft.png';
import middleRightCircleGradient from './assets/middleRightCircleGradient.png';
import astronaut from './assets/astronaut.png';
import star from './assets/star.png';

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
          <h1 className="text-9xl font-bold z-0 relative">SPACIO</h1>
          <div className="flex justify-center">
            <img
              src={arrowDown}
              alt="Arrow down"
              className="select-none cursor-pointer object-center mx-auto mt-20 scale-75"
            />
          </div>
        </div>

        <div className="flex text-white mt-96">
          <img
            src={middleRightCircleGradient}
            alt="Background gradient"
            className="right-0 absolute select-none"
          />

          <div className="ml-48 z-0">
            <h1 className="text-6xl font-extralight z-0 mb-20">
              About{" "}
              <span className="font-semibold" style={{ color: "#81689D" }}>
                Spacio
              </span>
            </h1>

            <p className="text-5xl font-light z-0 max-w-2xl">
              A one-of-a-kind educational application that offers endless excitement
              and knowledge for your brain. Download it and challenge yourself to learn
              as much as possible!
            </p>
        </div>

        <img src={astronaut} alt="Astronaut's image" className="w-6/12 h-2/4 select-none" />
        
          <div>
            <img src={star} alt="Stars" className='-rotate-45 absolute right-[45%] select-none scale-75'/>
            <img src={star} alt="Stars" className='rotate-[120deg] absolute right-1/2 top-[140vh] scale-[0.8] select-none'/>
            <img src={star} alt="Stars" className='rotate-[15deg] absolute right-[20%] top-[160vh] select-none'/>
            <img src={star} alt="Stars" className='-rotate-[27deg] absolute right-[5%] select-none'/>
          </div>
        </div>

        <div className='flex text-white text-5xl mt-24'>
          <h1 className='ml-48 font-extralight z-0'>You can download our app from here</h1>
          <button className='z-0 ring-4 bg-[#81689D] rounded-3xl p-6 ml-12 mb-5 ring-[#81689D] font-semibold shadow-lg shadow-[#81689D]'>Download</button>
        </div>


      </div>
    </div>
  );
}

export default App;
