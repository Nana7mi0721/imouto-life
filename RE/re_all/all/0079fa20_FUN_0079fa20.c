
void FUN_0079fa20(short param_1,char param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  char *pcVar6;
  
  iVar4 = param_5;
  if (param_4 == 8) {
    if (param_5 == 4) {
      puVar5 = &DAT_008389ac;
      param_5 = 0xb;
    }
    else {
      puVar5 = &DAT_00838988;
      param_5 = 3;
    }
  }
  else if (param_5 == 4) {
    puVar5 = &DAT_008389d8;
    param_5 = 0x22;
  }
  else {
    puVar5 = &DAT_00838990;
    param_5 = 0xc;
  }
  iVar1 = (short)param_4 * 2;
  iVar3 = (short)param_4 * 0x12;
  if (iVar4 < 1) {
    return;
  }
  pcVar6 = puVar5 + param_2;
  do {
    iVar2 = param_1 + iVar1 + (int)*pcVar6;
    *param_3 = iVar2;
    if (iVar3 < iVar1) {
      if (iVar1 < iVar2) {
LAB_0079fac3:
        iVar2 = iVar1;
      }
      else if (iVar2 < iVar3) {
        iVar2 = iVar3;
      }
    }
    else if (iVar3 < iVar2) {
      iVar2 = iVar3;
    }
    else if (iVar2 < iVar1) goto LAB_0079fac3;
    *param_3 = iVar2;
    pcVar6 = pcVar6 + param_5;
    param_3 = param_3 + 1;
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      return;
    }
  } while( true );
}

