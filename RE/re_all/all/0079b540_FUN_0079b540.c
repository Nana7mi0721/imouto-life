
undefined4 FUN_0079b540(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4;
  
  iVar2 = (int)(short)param_2;
  iVar1 = (int)*(short *)(param_1 + 0x914) * (int)(short)(iVar2 * 5);
  *(int *)(param_1 + 0x91c) = iVar2 * 5;
  local_4 = 0;
  if ((*(int *)(param_1 + 0x90c) != param_2) || (*(int *)(param_1 + 0x910) != param_3)) {
    local_4 = FUN_0079a620(param_1 + 0x980,iVar2 * 1000,param_3,0);
    *(int *)(param_1 + 0x910) = param_3;
  }
  if ((*(int *)(param_1 + 0x90c) != param_2) || (iVar1 != *(int *)(param_1 + 0x918))) {
    if (param_2 == 8) {
      if (*(int *)(param_1 + 0x914) == 4) {
        *(undefined **)(param_1 + 0x950) = &DAT_008380ac;
      }
      else {
        *(undefined **)(param_1 + 0x950) = &DAT_008380c4;
      }
    }
    else if (*(int *)(param_1 + 0x914) == 4) {
      *(undefined **)(param_1 + 0x950) = &DAT_00838088;
    }
    else {
      *(undefined **)(param_1 + 0x950) = &DAT_008380b8;
    }
    if (*(int *)(param_1 + 0x90c) != param_2) {
      *(int *)(param_1 + 0x920) = iVar2 * 0x14;
      if ((param_2 == 8) || (param_2 == 0xc)) {
        *(undefined4 *)(param_1 + 0x924) = 10;
        *(undefined **)(param_1 + 0xaac) = &DAT_008383f0;
      }
      else {
        *(undefined4 *)(param_1 + 0x924) = 0x10;
        *(undefined **)(param_1 + 0xaac) = &DAT_00838830;
      }
      if (param_2 == 0x10) {
        *(undefined **)(param_1 + 0x94c) = &DAT_008377fc;
      }
      else if (param_2 == 0xc) {
        *(undefined **)(param_1 + 0x94c) = &DAT_008377f4;
      }
      else if (param_2 == 8) {
        *(undefined **)(param_1 + 0x94c) = &DAT_008377e8;
      }
      *(undefined1 *)(param_1 + 0x908) = 10;
      *(undefined4 *)(param_1 + 0x948) = 1;
      *(undefined4 *)(param_1 + 0x904) = 100;
      *(undefined4 *)(param_1 + 0x1044) = 0;
      puVar3 = (undefined4 *)(param_1 + 0x544);
      for (iVar2 = 0xf0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      puVar3 = (undefined4 *)(param_1 + 0x504);
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
    }
    *(int *)(param_1 + 0x90c) = param_2;
    *(int *)(param_1 + 0x918) = iVar1;
  }
  return local_4;
}

