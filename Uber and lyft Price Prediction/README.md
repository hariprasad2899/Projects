# Uber and Lyft Price Prediction

A machine learning project that predicts ride prices for Uber and Lyft using various regression models, with an interactive GUI application for price comparison.

## 📋 Project Overview

This project analyzes ride-sharing data from Uber and Lyft to predict fare prices based on various factors such as distance, time, and ride type. The project includes data analysis, machine learning model training, and a user-friendly GUI application for comparing prices between different ride-sharing services.

## ✨ Features

- **Data Analysis**: Comprehensive exploratory data analysis (EDA) with visualizations
- **Price Prediction**: Multiple regression models (Linear and Polynomial) to predict ride prices
- **Time-based Analysis**: Analysis of price variations based on time of day, day of week, and other temporal features
- **Interactive GUI**: Tkinter-based application to compare Uber and Lyft prices for specific routes
- **Visualization**: Multiple plots and charts to visualize price patterns and model performance

## 🔧 Requirements

### Dependencies

```
pandas
numpy
matplotlib
seaborn
scikit-learn
tkinter
```

### Installation

1. Clone this repository or download the project files
2. Install the required dependencies:

```bash
pip install pandas numpy matplotlib seaborn scikit-learn
```

Note: `tkinter` is usually included with Python installations. If not available, install it separately for your operating system.

## 📁 Project Structure

```
SDAI Project/
│
├── Uber and lyft Price Prediction.ipynb    # Main Jupyter notebook with analysis and models
├── cab_rides.csv                           # Dataset file (ensure this is in the same directory)
├── Code_explanation.docx                   # Documentation
├── Project PPT.pdf                         # Project presentation
└── README.md                               # This file
```

## 📊 Dataset

The project uses `cab_rides.csv` which should contain the following columns:
- `distance`: Travel distance
- `cab_type`: Type of cab service (Uber/Lyft)
- `price`: Fare price
- `source`: Pickup location
- `destination`: Drop-off location
- `time_stamp`: Timestamp of the ride
- `name`: Vehicle/ride type name

**Note**: Ensure the `cab_rides.csv` file is placed in the same directory as the notebook before running the code.

## 🚀 Usage

### Running the Notebook

1. Open `Uber and lyft Price Prediction.ipynb` in Jupyter Notebook or JupyterLab
2. Ensure `cab_rides.csv` is in the same directory
3. Run the cells sequentially to:
   - Load and clean the data
   - Train machine learning models
   - Generate visualizations
   - Compare model performance

### Using the GUI Application

The notebook includes a GUI application that allows you to:
1. Select a source location from the dropdown menu
2. Select a destination location from the dropdown menu
3. Click "Submit" to compare Uber and Lyft prices for that route

The GUI will display:
- Average Lyft price
- Average Uber price
- Best price recommendation with vehicle type

## 🤖 Models Implemented

### 1. Linear Regression
- Predicts price based on distance and cab type
- Uses features: `distance`, `cab_type`

### 2. Polynomial Regression
- Uses polynomial features (degree=2) to capture non-linear relationships
- Provides potentially better accuracy for non-linear price patterns

### 3. Time-based Linear Regression
- Incorporates temporal features: `hour`, `day_of_week`, `distance`
- Accounts for price variations based on time

## 📈 Model Performance

The models are evaluated using:
- **RMSE (Root Mean Squared Error)**: Lower is better
- **R² Score**: Higher is better (closer to 1.0)

Run the notebook to see the specific performance metrics for your dataset.

## 📝 Notes

- The dataset is cleaned by removing missing values and duplicates
- Categorical variables are encoded (Lyft: 0, Uber: 1)
- Data is split into training (80%) and testing (20%) sets with a random state of 42
- All timestamps are converted to datetime format for temporal analysis

## 🎯 Use Cases

- Compare ride prices between Uber and Lyft
- Predict ride costs before booking
- Analyze pricing patterns based on distance and time
- Make informed decisions about ride-sharing services

## 📚 Future Enhancements

- Add more advanced models (Random Forest, Gradient Boosting, Neural Networks)
- Include weather data and traffic conditions
- Real-time price comparison API
- Mobile application version
- Surge pricing analysis


