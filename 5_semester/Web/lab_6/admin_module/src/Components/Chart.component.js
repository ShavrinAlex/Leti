import React from "react";
import Chart from 'chart.js/auto';
import { Line } from "react-chartjs-2";


function Graphic(props) {
    return (
        <Line
            data={
                props.value
            }
            options={
                {
                    plugins: {
                        legend: {
                            display: false
                        }
                    }
                }
            }
            style={{backgroundColor:"white"}}
        />
    );
}

export default Graphic;