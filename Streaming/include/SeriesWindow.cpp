SeriesWindow::SeriesWindow(string sN){
    seriesName=sN;
}
string SeriesWindow::printWindow(){
    string window=seriesName+", episodes:\n"+collectionData;
    return window;
}
