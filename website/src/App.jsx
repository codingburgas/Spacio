import { useState } from 'react';
import './App.css';
import logo from './assets/logo.png';
import arrowDown from './assets/arrow.png';
import smallCircleTopLeft from './assets/smallGradientCircleTopLeft.png';
import gradientCircleTopLeft from './assets/gradientCircleTopLeft.png'

function App() {
  return (
  <div className='bg-[#080310] min-h-screen w-screen overflow-x-hidden'>
    <div>
      <div className='overflow-x-hidden'>
          <img src={smallCircleTopLeft} alt="Background gradient" className='top-0 left-0 absolute select-none'/>
          <img src={gradientCircleTopLeft} alt="Background gradient" className='top-0 absolute select-none'/>
      </div>

      <div className="flex items-center text-white">
        <img src={logo} alt="Spacio's logo" className="w-16 h-auto select-none z-0" />
        <h2 className="ml-2 font-bold z-0">Spacio</h2>
      </div>
        
      <div className='text-center my-40 mt-60 text-white'>
        <h1 className='text-9xl font-bold z-0 relative'>SPACIO</h1>
        <div className="flex justify-center">
          <img src={arrowDown} alt="Arrow down" className='select-none cursor-pointer object-center mx-auto mt-20 scale-75'/>
        </div>
      </div>
    </div>
  </div>
  );
}

export default App;
