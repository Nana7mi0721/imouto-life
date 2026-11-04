
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0065ecc0(double param_1,double param_2)

{
  short sVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  bool bVar7;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST1;
  double *local_334;
  undefined4 *local_330;
  int local_32c;
  double adStack_328 [99];
  undefined8 local_10;
  
  if (DAT_00f3fbf4 == 0) {
    puVar2 = &local_10;
    iVar4 = 100;
    do {
      *(undefined4 *)puVar2 = 0;
      *(undefined4 *)((int)puVar2 + 4) = 0x40000000;
      iVar4 = iVar4 + -1;
      puVar2 = puVar2 + -1;
    } while (iVar4 != 0);
    local_334 = (double *)0xa2;
    psVar6 = &DAT_00a0b00c;
    do {
      local_330 = (undefined4 *)(*psVar6 + -1);
      if (((psVar6 == &DAT_00a0b00c) || (psVar6 == (short *)&DAT_00a0aafc)) ||
         (iVar4 = (int)local_330, (int)local_330 < 1)) {
        iVar4 = 1;
      }
      if (-1 < (int)local_330) {
        fVar8 = (((float10)(int)local_334 + (float10)_DAT_00804a60) * (float10)_DAT_008053c0 +
                (float10)_DAT_00805390) - (float10)_DAT_008053b8;
        do {
          fpatan(fVar8,(((float10)(int)local_330 + (float10)_DAT_00804a60) * (float10)_DAT_008053c0
                       + (float10)*(float *)(psVar6 + -2)) - (float10)_DAT_008053b0);
          iVar3 = __ftol();
          fVar8 = ABS(extraout_ST0 - ((float10)iVar3 + (float10)_DAT_00804a60));
          if (fVar8 < (float10)adStack_328[iVar3]) {
            sVar1 = psVar6[1];
            adStack_328[iVar3] = (double)fVar8;
            *(int *)(&DAT_00f3fa64 + iVar3 * 4) = (int)sVar1 + (int)local_330;
          }
          local_330 = (undefined4 *)((int)local_330 - iVar4);
          fVar8 = extraout_ST1;
        } while (-1 < (int)local_330);
      }
      local_334 = (double *)((int)local_334 + -1);
      bVar7 = psVar6 != (short *)&DAT_00a0aafc;
      psVar6 = psVar6 + -4;
    } while (bVar7);
    local_334 = (double *)&local_10;
    iVar4 = 99;
    local_330 = &DAT_00f3fbf0;
    do {
      if (_DAT_00805398 < *local_334) {
        iVar3 = 1;
        do {
          if (adStack_328[(iVar3 + iVar4) % 100] < _DAT_00805398) break;
          iVar3 = iVar3 + 1;
        } while (iVar3 < 0x32);
        local_32c = iVar4 + 99;
        iVar5 = 1;
        do {
          if (adStack_328[local_32c % 100] < _DAT_00805398) break;
          iVar5 = iVar5 + 1;
          local_32c = local_32c + -1;
        } while (iVar5 < 0x32);
        if (iVar3 < iVar5) {
          iVar3 = iVar3 + iVar4;
        }
        else {
          iVar3 = (iVar4 - iVar5) + 100;
        }
        *local_330 = *(undefined4 *)(&DAT_00f3fa64 + (iVar3 % 100) * 4);
      }
      iVar4 = iVar4 + -1;
      local_334 = local_334 + -1;
      bVar7 = local_330 != (undefined4 *)&DAT_00f3fa64;
      local_330 = local_330 + -1;
    } while (bVar7);
    DAT_00f3fbf4 = 1;
  }
  fpatan((float10)param_2 - (float10)_DAT_008053b8,(float10)param_1 - (float10)_DAT_008053b0);
  iVar4 = __ftol();
  return *(undefined4 *)(&DAT_00f3fa64 + iVar4 * 4);
}

