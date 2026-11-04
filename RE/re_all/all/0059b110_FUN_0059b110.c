
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0059b110(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_3 == -1) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if (param_1 == 1) {
      FUN_005d3ab0(0,0x18,3);
      FUN_005d3ab0(1,0x18,3);
      FUN_005d3ab0(2,0x18,3);
      FUN_005d3ab0(3,0x18,3);
      FUN_005d39b0(0x10,param_2);
      FUN_005d39b0(0x11,param_2);
      FUN_005d39b0(0x12,param_2);
      FUN_005d39b0(0x13,param_2);
    }
    else {
      FUN_005d3ab0(0,0x18,0);
      FUN_005d3ab0(1,0x18,0);
      FUN_005d3ab0(2,0x18,0);
      FUN_005d3ab0(3,0x18,0);
    }
    DAT_00e8071c = param_1;
    DAT_00e80720 = param_1;
    _DAT_00e80724 = param_1;
    _DAT_00e80728 = param_1;
    puVar2 = param_2;
    puVar3 = &DAT_00e8075c;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = param_2;
    puVar3 = &DAT_00e8079c;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = param_2;
    puVar3 = &DAT_00e807dc;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_00e8081c;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
    return 0;
  }
  if ((param_3 < DAT_00ddb4b4) && (((&DAT_00e8071c)[param_3] != 0 || (param_1 != 0)))) {
    FUN_00568ca0(0);
    if (DAT_00dda46c != 0) {
      FUN_00584d70();
    }
    if (param_1 == 1) {
      if ((&DAT_00e8071c)[param_3] == 0) {
        FUN_005d3ab0(param_3,0x18,3);
      }
      FUN_005d39b0(param_3 + 0x10,param_2);
    }
    else {
      FUN_005d3ab0(param_3,0x18,0);
    }
    (&DAT_00e8071c)[param_3] = param_1;
    puVar2 = &DAT_00e8075c + param_3 * 0x10;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *param_2;
      param_2 = param_2 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  return 0;
}

