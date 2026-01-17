# Tourist Behavior Analysis

A comprehensive big data analytics project that analyzes tourist behavior patterns using photo metadata from Flickr. This project performs geospatial clustering and seasonal trend analysis on tourist activity data from San Francisco and India to identify popular locations and temporal patterns.

## 📋 Project Overview

This project analyzes tourist behavior by processing photo metadata from social media platforms (Flickr) to:
- **Cluster tourist locations** using density-based clustering algorithms (HDBSCAN and OPTICS)
- **Identify popular tourist spots** through geospatial clustering
- **Analyze seasonal trends** in tourist visits using time-series analysis
- **Visualize patterns** on maps and charts

## 🎯 Key Features

1. **Metadata Processing**: Preprocesses raw photo metadata using NLP techniques (tokenization, stemming, stopword removal)
2. **Geospatial Clustering**: 
   - HDBSCAN (Hierarchical Density-Based Spatial Clustering)
   - OPTICS (Ordering Points To Identify the Clustering Structure)
3. **Seasonal Trend Analysis**: Polynomial regression to identify seasonal patterns in tourist visits
4. **Geographic Visualization**: Interactive maps showing cluster locations using Basemap
5. **Multi-Dataset Support**: Analysis performed on both San Francisco and India datasets

## 📁 Project Structure

```
Big Data Project/
├── GROUP_1.ipynb                          # Main Jupyter notebook with all analysis
├── Filtered1M.csv                         # Raw San Francisco dataset
├── fullindia.csv                          # Raw India dataset
├── TP1M.csv                               # Processed San Francisco data (intermediate)
├── TP_op1M.csv                            # Preprocessed San Francisco data (final)
├── TP1Mfullindia.csv                      # Processed India data (intermediate)
├── preprocessed_india_data.csv            # Preprocessed India data (final)
├── sf_hdb_before_clusters.png            # San Francisco: Before clustering
├── sf_hdb_after_clusters.png             # San Francisco: After HDBSCAN clustering
├── sf_optics_after_clusters.png          # San Francisco: After OPTICS clustering
├── sf_arrivalOfTouristsInParticularMonth.png  # San Francisco: Seasonal trends
├── sf_averageNoOfTouristsInParticularMonth.png # San Francisco: Monthly averages
├── india_hdb_before_clusters.png         # India: Before clustering
├── india_hdb_after_clusters.png          # India: After HDBSCAN clustering
├── india_optics_after_clusters.png       # India: After OPTICS clustering
├── india_arrivalOfTouristsInParticularMonth.png  # India: Seasonal trends
├── india_averageNoOfTouristsInParticularMonth.png # India: Monthly averages
└── README.md                              # This file
```

## 🔧 Technologies Used

### Python Libraries
- **pandas**: Data manipulation and analysis
- **numpy**: Numerical computing
- **nltk**: Natural Language Processing (tokenization, stemming, stopwords)
- **scikit-learn**: Machine learning (PolynomialFeatures, LinearRegression, OPTICS)
- **hdbscan**: Hierarchical density-based clustering
- **matplotlib**: Data visualization
- **mpl_toolkits.basemap**: Geographic mapping
- **folium**: Interactive map creation

### Data Processing
- Text preprocessing (lowercasing, stemming, stopword removal)
- Geospatial coordinate conversion (degrees to radians)
- Time-series data aggregation

### Clustering Algorithms
- **HDBSCAN**: Hierarchical density-based clustering with noise detection
- **OPTICS**: Density-based clustering that finds clusters of varying densities

## 📊 Dataset Description

### Data Fields
The datasets contain photo metadata with the following key fields:
- **LineNo**: Line number
- **PhotoID**: Unique photo identifier
- **UserID**: User who took the photo
- **DateTaken**: Timestamp when photo was taken
- **Latitude**: GPS latitude coordinate
- **Longitude**: GPS longitude coordinate
- **Accuracy**: GPS accuracy level

### Dataset Details
- **San Francisco Dataset** (`Filtered1M.csv`): ~2,671 records of photos taken in San Francisco area
- **India Dataset** (`fullindia.csv`): Photos taken across India

**Time Range**: 2004-2013 (10 years of data)

## 🚀 Getting Started

### Prerequisites

```bash
pip install pandas numpy nltk scikit-learn hdbscan matplotlib basemap folium
```

### Installation

1. Clone or download this repository
2. Install required Python packages:
   ```bash
   pip install pandas numpy nltk scikit-learn hdbscan matplotlib basemap folium
   ```
3. Download NLTK stopwords (automatically done in the notebook):
   ```python
   import nltk
   nltk.download('stopwords')
   ```

### Running the Analysis

1. Open `GROUP_1.ipynb` in Jupyter Notebook or JupyterLab
2. Ensure the CSV data files are in the same directory:
   - `Filtered1M.csv` (for San Francisco analysis)
   - `fullindia.csv` (for India analysis)
3. Run the notebook cells sequentially:
   - **Cells 1-6**: Metadata processing for San Francisco
   - **Cells 7-13**: Metadata processing for India
   - **Cells 14-27**: HDBSCAN clustering for both datasets
   - **Cells 14-20**: OPTICS clustering for both datasets
   - **Cells 21-27**: Seasonal trend analysis for both datasets

## 📈 Analysis Workflow

### 1. Metadata Processing
- Extract relevant columns from raw CSV files
- Apply text preprocessing (lowercasing, stemming, stopword removal)
- Clean and normalize geospatial coordinates and dates
- Output: Preprocessed CSV files ready for clustering

### 2. Geospatial Clustering

#### HDBSCAN Clustering
- Parameters:
  - `min_cluster_size=20`: Minimum points in a cluster
  - `metric='haversine'`: Distance metric for geographic coordinates
  - `algorithm='best'`: Algorithm variant
- Output: Cluster labels and exemplar points for each cluster

#### OPTICS Clustering
- Parameters:
  - `min_samples=10`: Minimum samples in a neighborhood
  - `max_eps=100`: Maximum distance for clustering
  - `metric='haversine'`: Geographic distance metric
- Output: Cluster assignments with varying densities

### 3. Seasonal Trend Analysis
- Aggregate photo counts by month and year (2004-2013)
- Apply polynomial regression (degree 2-3) for each month
- Calculate Mean Absolute Error (MAE) for trend predictions
- Visualize seasonal patterns and tourist arrival trends

### 4. Visualization
- **Before/After Clustering Maps**: Show data distribution and identified clusters
- **Seasonal Trend Charts**: Display monthly patterns and tourist arrivals
- **Color-coded Clusters**: Different colors for each cluster, black for outliers

## 📊 Results and Insights

The analysis generates several visualizations:

1. **Cluster Maps**: Identify popular tourist locations and hotspots
2. **Seasonal Patterns**: Understand peak tourism months
3. **Trend Analysis**: Predict future tourist behavior patterns
4. **Geographic Distribution**: Visualize spatial patterns of tourist activity

### Key Outputs
- Preprocessed datasets for further analysis
- Cluster representatives (exemplars) for each identified cluster
- Seasonal component metrics for each month
- High-resolution map visualizations (300 DPI)

## 🔍 Algorithm Details

### HDBSCAN
- **Advantages**: Handles noise, finds clusters of varying densities, no need to specify number of clusters
- **Use Case**: Identifying tourist hotspots with natural groupings
- **Time Complexity**: O(n log n) for building minimum spanning tree

### OPTICS
- **Advantages**: Handles varying cluster densities, identifies hierarchical structure
- **Use Case**: Finding both dense and sparse tourist areas
- **Time Complexity**: O(n²) in worst case, O(n log n) with spatial indexing

### Polynomial Regression
- **Purpose**: Model seasonal trends over the 10-year period
- **Method**: Degree 2-3 polynomial features with linear regression
- **Metrics**: Mean Absolute Error (MAE) for model evaluation

## 📝 Code Organization

### Metadata Processing Section
- **San Francisco Processing**: Cells 1-6
- **India Processing**: Cells 7-13
- Functions: Text cleaning, stemming, stopword removal

### Clustering Section
- **HDBSCAN Implementation**: Separate cells for SF and India
- **OPTICS Implementation**: Separate cells for SF and India
- Functions: Coordinate conversion, clustering, visualization

### Seasonal Analysis Section
- **Time-series Aggregation**: Monthly and yearly grouping
- **Regression Analysis**: Polynomial fitting for each month
- **Visualization**: Trend plots and seasonal component charts

## 📈 Performance Metrics

### Clustering Evaluation
- Number of clusters identified
- Noise/outlier points detected
- Cluster density and spread

### Regression Evaluation
- Mean Absolute Error (MAE) per month
- Seasonal component values
- Trend prediction accuracy

## 🎓 Key Concepts Demonstrated

1. **Big Data Processing**: Handling large-scale geospatial datasets
2. **NLP Techniques**: Text preprocessing for metadata cleaning
3. **Unsupervised Learning**: Density-based clustering algorithms
4. **Time-Series Analysis**: Seasonal pattern detection
5. **Geographic Information Systems**: Spatial data visualization
6. **Data Mining**: Extracting patterns from social media data

## 🔧 Configuration Options

### Clustering Parameters
- `min_cluster_size`: Adjust cluster sensitivity (default: 20)
- `min_samples`: Control neighborhood size (default: 10)
- `max_eps`: Set maximum distance for clustering (default: 100)

### Map Visualization
- `projection`: Map projection type (default: 'merc')
- `resolution`: Map resolution (default: 'l' for low)
- `dpi`: Image quality (default: 300)

## 📝 Notes

- The coordinate conversion to radians is necessary for the haversine distance metric
- Outliers (noise points) are labeled as -1 in cluster labels
- The analysis covers a 10-year period (2004-2013) for comprehensive trend analysis
- Maps use Mercator projection for accurate geographic representation
- Some text preprocessing is applied to numeric fields (may need refinement for production use)

## 🐛 Known Limitations

- Text preprocessing applied to numeric coordinates (consider separate handling)
- HDBSCAN and OPTICS require coordinate conversion for geographic data
- Basemap library may have installation issues on some systems (consider alternatives like Cartopy)

## 🔄 Future Enhancements

- Add more clustering algorithms (DBSCAN, K-means for comparison)
- Implement real-time data processing for live analysis
- Add sentiment analysis of photo tags
- Create interactive dashboards with Plotly/Dash
- Integrate weather data for correlation analysis
- Expand to more geographic regions

## 🤝 Contributing

This is an academic/research project. For questions or suggestions, please refer to the project documentation or contact the development team.

## 📄 License

This project is for educational and research purposes. Data sources and licensing information can be found in the original Flickr photo metadata.

## 🙏 Acknowledgments

- Flickr for providing photo metadata
- Open-source Python community for excellent data science libraries
- Geographic data visualization tools (Basemap, Folium)
- Contributors and researchers in the field of geospatial analytics

## 📚 References

- HDBSCAN documentation: https://hdbscan.readthedocs.io/
- OPTICS algorithm paper: "OPTICS: Ordering Points To Identify the Clustering Structure"
- Scikit-learn clustering: https://scikit-learn.org/stable/modules/clustering.html
- NLTK documentation: https://www.nltk.org/

## 🎯 Use Cases

- **Tourism Planning**: Identify popular destinations for infrastructure development
- **Seasonal Marketing**: Understand peak tourism periods for promotional campaigns
- **Urban Planning**: Analyze spatial patterns for city development
- **Research**: Academic research on human mobility and behavior patterns

- **Business Intelligence**: Insights for hospitality and travel industry
