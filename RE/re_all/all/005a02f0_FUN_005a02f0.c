
undefined4 FUN_005a02f0(undefined4 *param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80 [12];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_40 [64];
  
  if (DAT_00f3a04c != 0) {
    FUN_005d39b0(2,param_1);
    FUN_00585710(local_40,param_1);
    FUN_0059cb80(&DAT_00ddb600,0,0,6,local_40,4,1);
    puVar3 = local_80;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    iVar1 = 0;
    puVar2 = &DAT_00e79cd4;
    iVar4 = 0x20;
    do {
      FUN_00586170(&local_ac,puVar2 + 0xc,local_80);
      FUN_00586170(&local_b8,puVar2,&DAT_00a383d8);
      local_a0 = local_b8;
      local_9c = local_b4;
      local_98 = local_b0;
      local_94 = 0x3f800000;
      local_90 = local_ac;
      local_8c = local_a8;
      local_88 = local_a4;
      local_84 = 0;
      if (iVar1 < 4) {
        FUN_0059cb80(&DAT_00ddb600,0,0,iVar4 + -0x12,&local_a0,2,1);
      }
      FUN_0059cb80(&DAT_00ddb600,3,0,iVar4,&local_a0,2,1);
      puVar2 = puVar2 + 0x68;
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + 7;
    } while ((int)puVar2 < 0xe79f44);
  }
  return 0;
}

