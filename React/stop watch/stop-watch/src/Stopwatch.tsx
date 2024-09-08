import React, { useState, useEffect } from 'react';

const StopWatch: React.FC = () => {
  const [seconds, setSeconds] = useState(0);
  const [isRunning, setIsRunning] = useState(false);

  useEffect(() => {
    let interval: NodeJS.Timeout;

    if (isRunning) {
      interval = setInterval(() => {
        setSeconds((prevSeconds) => prevSeconds + 1);
      }, 1000);
    }

    return () => clearInterval(interval);
  }, [isRunning]);

  const startStopwatch = () => {
    setIsRunning(true);
  };

  const stopStopwatch = () => {
    setIsRunning(false);
  };

  const resetStopwatch = () => {
    setSeconds(0);
    setIsRunning(false);
  };

  const formatTime = (time: number) => {
    const hours = Math.floor(time / 3600);
    const minutes = Math.floor((time % 3600) / 60);
    const seconds = time % 60;

    return `${hours.toString().padStart(2, '0')}:${minutes
      .toString()
      .padStart(2, '0')}:${seconds.toString().padStart(2, '0')}`;
  };

  return (
    <div>
      <h2>Stopwatch</h2>
      <p>{formatTime(seconds)}</p>
      {!isRunning ? (
        <button onClick={startStopwatch}>Start</button>
      ) : (
        <button onClick={stopStopwatch}>Stop</button>
      )}
      <button onClick={resetStopwatch}>Reset</button>
    </div>
  );
};

export default StopWatch;