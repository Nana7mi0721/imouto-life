
/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_0057a7b0(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int local_1408;
  uint *local_1404;
  int aiStack_1400 [256];
  uint local_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x57a7ba;
  local_1408 = 0;
  local_1404 = (uint *)0x0;
  if (param_2 == 0) {
    return 0;
  }
  iVar3 = FUN_005739b0(param_2,param_1,0);
  uVar1 = iVar3 + 0x40;
  if (uVar1 < 0x1001) {
    puVar4 = local_1000;
  }
  else {
    puVar4 = (uint *)FUN_0056e030(uVar1,"..\\..\\..\\..\\Source\\Library\\Main\\DxChar.cpp",0x1c29);
    if (puVar4 == (uint *)0x0) {
      return -1;
    }
    local_1404 = puVar4;
  }
  FUN_0056d380(puVar4,0,uVar1);
  FUN_005739b0(param_2,param_1,puVar4);
  uVar1 = *puVar4;
  do {
    if (uVar1 == 0) {
LAB_0057a8d5:
      if (local_1404 != (uint *)0x0) {
        FUN_0056e1d0(local_1404);
      }
      return local_1408;
    }
    if (((0x2f < uVar1) && (uVar1 < 0x3a)) || (uVar1 == 0x2d)) {
      uVar1 = *puVar4;
      if (uVar1 != 0) {
        if (uVar1 == 0x2d) {
          puVar4 = puVar4 + 1;
        }
        iVar3 = 0;
        uVar2 = *puVar4;
        while (((uVar2 != 0 && (0x2f < uVar2)) && (uVar2 < 0x3a))) {
          puVar4 = puVar4 + 1;
          aiStack_1400[iVar3] = uVar2 - 0x30;
          iVar3 = iVar3 + 1;
          uVar2 = *puVar4;
        }
        local_1408 = 0;
        iVar5 = 1;
        while (iVar3 = iVar3 + -1, -1 < iVar3) {
          local_1408 = local_1408 + aiStack_1400[iVar3] * iVar5;
          iVar5 = iVar5 * 10;
        }
        if (uVar1 == 0x2d) {
          local_1408 = -local_1408;
        }
      }
      goto LAB_0057a8d5;
    }
    uVar1 = puVar4[1];
    puVar4 = puVar4 + 1;
  } while( true );
}

