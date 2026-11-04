
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056b830(int param_1,short *param_2)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  short *psVar6;
  short *local_1408;
  short *local_1404;
  short local_1400 [1024];
  undefined1 local_c00 [3068];
  undefined4 uStack_4;
  
  uStack_4 = 0x56b83a;
  local_1404 = (short *)0x0;
  if (param_1 != 0) {
    FUN_0052ea50(param_1,param_2);
  }
  if ((DAT_00aaf118 != 1) && ((DAT_00aaf110 != 0 || (iVar3 = FUN_0056b620(), -1 < iVar3)))) {
    iVar3 = 0;
    sVar2 = *param_2;
    while (sVar2 != 0) {
      iVar3 = iVar3 + 1;
      sVar2 = param_2[iVar3];
    }
    uVar1 = DAT_00ab0124 + 0x10 + iVar3 * 2;
    if (uVar1 < 0x400) {
      local_1408 = local_1400;
    }
    else {
      local_1408 = (short *)FUN_0056e030(uVar1 * 2,0,0xffffffff);
      local_1404 = local_1408;
    }
    psVar6 = local_1408;
    if (DAT_00ab0128 == 0) {
      if (DAT_00aaf114 == 0) {
        iVar3 = FUN_00550060(0);
        FUN_0056d2b0(local_1408,&PTR_LAB_00640021_4_007d788c,iVar3 - _DAT_00aaf11c);
        iVar3 = FUN_0050e220(local_1408);
        psVar6 = local_1408 + iVar3;
      }
      if (DAT_00ab0124 != 0) {
        iVar3 = 0;
        if (0 < DAT_00ab0124) {
          do {
            *psVar6 = 9;
            iVar3 = iVar3 + 1;
            psVar6 = psVar6 + 1;
          } while (iVar3 < DAT_00ab0124);
        }
        *psVar6 = 0;
      }
    }
    psVar4 = (short *)FUN_0056d0d0(param_2,10);
    psVar5 = param_2;
    if (psVar4 != (short *)0x0) {
      do {
        if ((param_2 != psVar4) && (psVar4[-1] == 0xd)) break;
        iVar3 = (int)psVar4 - (int)psVar5 >> 1;
        FUN_0056d420(psVar6,psVar5,iVar3 * 2);
        psVar6 = psVar6 + iVar3;
        psVar5 = psVar4 + 1;
        *psVar6 = 0xd;
        psVar6[1] = 10;
        psVar6[2] = 0;
        psVar6 = psVar6 + 2;
        psVar4 = (short *)FUN_0056d0d0(psVar5,10);
      } while (psVar4 != (short *)0x0);
    }
    FUN_0056cf10(psVar6,psVar5);
    iVar3 = 0;
    sVar2 = *local_1408;
    while (sVar2 != 0) {
      iVar3 = iVar3 + 1;
      sVar2 = local_1408[iVar3];
    }
    DAT_00ab0128 = (uint)(local_1408[iVar3 + -1] != 10);
    FUN_0056b590();
    FUN_005d6790(local_c00,local_1408);
    if (local_1404 != (short *)0x0) {
      FUN_0056e1d0(local_1404);
    }
  }
  return 0xffffffff;
}

