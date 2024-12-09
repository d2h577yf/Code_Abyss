void AdjustSortTable(int aSortTable[],struct medalCountry aMedalCountry[], int iCounter, int iNo, int iMedalType){
    struct medalCountry temple;
    for(int i = 1;i < iCounter;i++){
        for(int j = 0;j < iCounter - i;j++){
            if(aMedalCountry[aSortTable[j]].iMedalNum[0] < aMedalCountry[aSortTable[j+1]].iMedalNum[0]){
                temple = aMedalCountry[j];
                aMedalCountry[j] = aMedalCountry[j+1];
                aMedalCountry[j+1] = temple;
            }else if (aMedalCountry[aSortTable[j]].iMedalNum[0] == aMedalCountry[aSortTable[j+1]].iMedalNum[0]){
                if(aMedalCountry[aSortTable[j]].iMedalNum[1] < aMedalCountry[aSortTable[j+1]].iMedalNum[1]){
                    temple = aMedalCountry[j];
                    aMedalCountry[j] = aMedalCountry[j+1];
                    aMedalCountry[j+1] = temple;
                }else if (aMedalCountry[aSortTable[j]].iMedalNum[1] == aMedalCountry[aSortTable[j+1]].iMedalNum[1]){
                    if(aMedalCountry[aSortTable[j]].iMedalNum[2] < aMedalCountry[aSortTable[j+1]].iMedalNum[2]){
                        temple = aMedalCountry[j];
                        aMedalCountry[j] = aMedalCountry[j+1];
                        aMedalCountry[j+1] = temple;
                    }else if (aMedalCountry[aSortTable[j]].iMedalNum[2] == aMedalCountry[aSortTable[j+1]].iMedalNum[2]){
                        if(aMedalCountry[aSortTable[j]].sName[0] > aMedalCountry[aSortTable[j+1]].sName[0]){
                            temple = aMedalCountry[j];
                            aMedalCountry[j] = aMedalCountry[j+1];
                            aMedalCountry[j+1] = temple;
                        }else if (aMedalCountry[aSortTable[j]].sName[0] == aMedalCountry[aSortTable[j+1]].sName[0]){
                            if(aMedalCountry[aSortTable[j]].sName[1] > aMedalCountry[aSortTable[j+1]].sName[0]){
                                temple = aMedalCountry[j];
                                aMedalCountry[j] = aMedalCountry[j+1];
                                aMedalCountry[j+1] = temple;
                            }else if(aMedalCountry[aSortTable[j]].sName[1] == aMedalCountry[aSortTable[j+1]].sName[1]){
                                if(aMedalCountry[aSortTable[j]].sName[2] > aMedalCountry[aSortTable[j+1]].sName[2]){
                                    temple = aMedalCountry[j];
                                    aMedalCountry[j] = aMedalCountry[j+1];
                                    aMedalCountry[j+1] = temple;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}