
undefined4
FUN_0065bd80(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
            double *param_6)

{
  double dVar1;
  short sVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  float *pfVar5;
  undefined4 uVar6;
  float fVar7;
  uint uVar8;
  float *pfVar9;
  
  pfVar5 = (float *)FUN_006507d0(param_5 * 8);
  if (pfVar5 == (float *)0x0) {
    FUN_006512e0(*(undefined4 *)(param_1 + 0x274),"TIFFWriteDirectoryTagSampleformatArray",
                 s_Out_of_memory_00a066e4);
    return 0;
  }
  sVar2 = *(short *)(param_1 + 0x56);
  if (sVar2 == 1) {
    if (*(ushort *)(param_1 + 0x54) < 9) {
      uVar8 = 0;
      if (param_5 != 0) {
        do {
          uVar3 = __ftol();
          *(undefined1 *)(uVar8 + (int)pfVar5) = uVar3;
          uVar8 = uVar8 + 1;
        } while (uVar8 < param_5);
      }
      uVar6 = FUN_0065c0a0(param_1,param_2,param_3,param_4,param_5,pfVar5);
    }
    else if (*(ushort *)(param_1 + 0x54) < 0x11) {
      if (param_5 != 0) {
        param_6 = (double *)param_5;
        pfVar9 = pfVar5;
        do {
          uVar4 = __ftol();
          *(undefined2 *)pfVar9 = uVar4;
          pfVar9 = (float *)((int)pfVar9 + 2);
          param_6 = (double *)((int)param_6 - 1);
        } while (param_6 != (double *)0x0);
      }
      uVar6 = FUN_0065c160(param_1,param_2,param_3,param_4,param_5,pfVar5);
    }
    else {
      if (param_5 != 0) {
        param_6 = (double *)param_5;
        pfVar9 = pfVar5;
        do {
          fVar7 = (float)__ftol();
          *pfVar9 = fVar7;
          pfVar9 = pfVar9 + 1;
          param_6 = (double *)((int)param_6 - 1);
        } while (param_6 != (double *)0x0);
      }
      uVar6 = FUN_0065c2c0(param_1,param_2,param_3,param_4,param_5,pfVar5);
    }
  }
  else if (sVar2 == 2) {
    if (*(ushort *)(param_1 + 0x54) < 9) {
      uVar8 = 0;
      if (param_5 != 0) {
        do {
          uVar3 = __ftol();
          *(undefined1 *)(uVar8 + (int)pfVar5) = uVar3;
          uVar8 = uVar8 + 1;
        } while (uVar8 < param_5);
      }
      uVar6 = FUN_0065c0e0(param_1,param_2,param_3,param_4,param_5,pfVar5);
    }
    else if (*(ushort *)(param_1 + 0x54) < 0x11) {
      if (param_5 != 0) {
        param_6 = (double *)param_5;
        pfVar9 = pfVar5;
        do {
          uVar4 = __ftol();
          *(undefined2 *)pfVar9 = uVar4;
          pfVar9 = (float *)((int)pfVar9 + 2);
          param_6 = (double *)((int)param_6 - 1);
        } while (param_6 != (double *)0x0);
      }
      uVar6 = FUN_0065c240(param_1,param_2,param_3,param_4,param_5,pfVar5);
    }
    else {
      if (param_5 != 0) {
        param_6 = (double *)param_5;
        pfVar9 = pfVar5;
        do {
          fVar7 = (float)__ftol();
          *pfVar9 = fVar7;
          pfVar9 = pfVar9 + 1;
          param_6 = (double *)((int)param_6 - 1);
        } while (param_6 != (double *)0x0);
      }
      uVar6 = FUN_0065c300(param_1,param_2,param_3,param_4,param_5,pfVar5);
    }
  }
  else {
    if (sVar2 != 3) {
      FUN_006507e0(pfVar5);
      return 0;
    }
    if (*(ushort *)(param_1 + 0x54) < 0x21) {
      if (param_5 != 0) {
        pfVar9 = pfVar5;
        uVar8 = param_5;
        do {
          dVar1 = *param_6;
          param_6 = param_6 + 1;
          *pfVar9 = (float)dVar1;
          pfVar9 = pfVar9 + 1;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      uVar6 = FUN_0065c480(param_1,param_2,param_3,param_4,param_5,pfVar5);
    }
    else {
      uVar6 = FUN_0065c4c0(param_1,param_2,param_3,param_4,param_5,param_6);
    }
  }
  FUN_006507e0(pfVar5);
  return uVar6;
}

