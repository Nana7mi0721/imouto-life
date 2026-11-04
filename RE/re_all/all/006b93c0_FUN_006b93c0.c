
int FUN_006b93c0(int param_1,int param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int *local_4;
  
  iVar1 = FUN_006bc890(param_1,param_2,3);
  if (-1 < iVar1) {
    iVar1 = FUN_006bee30(param_1 + 0xc9c8,param_3);
    if (iVar1 < 0) {
      FUN_006bd6e0(param_1);
      return iVar1;
    }
    pvVar2 = _malloc(*(int *)(param_1 + 0xb4) * 0x81);
    *(void **)(param_1 + 0xd108) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      FUN_006bef40(param_1 + 0xc9c8);
      FUN_006bd6e0(param_1);
      return -1;
    }
    iVar1 = param_1 + 0x970;
    iVar5 = 0x40;
    piVar3 = (int *)(param_1 + 0x370);
    do {
      iVar7 = 3;
      do {
        iVar4 = 2;
        do {
          *piVar3 = iVar1;
          iVar1 = iVar1 + 0x80;
          piVar3 = piVar3 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_006be580((int *)(param_1 + 0x370),param_1 + 0xd118,param_3 + 0x140);
    local_4 = (int *)(param_1 + 0xd218);
    iVar5 = 0;
    param_2 = 0;
    iVar1 = 0;
    while( true ) {
      do {
        iVar7 = 0;
        piVar3 = (int *)(param_1 + 0x370 + (param_2 + iVar1) * 4);
        do {
          iVar4 = *piVar3;
          piVar3 = piVar3 + 2;
          iVar5 = iVar5 + ((uint)*(ushort *)(iVar4 + 0x30) + (uint)*(ushort *)(iVar4 + 0x24) +
                           (uint)*(ushort *)(iVar4 + 0x22) + (uint)*(ushort *)(iVar4 + 0x18) <<
                          (iVar7 == 0));
          iVar7 = iVar7 + 1;
        } while (iVar7 < 3);
        iVar1 = iVar1 + 1;
      } while (iVar1 < 2);
      *local_4 = -(iVar5 >> 0xb);
      local_4 = local_4 + 1;
      param_2 = param_2 + 6;
      if (0x17f < param_2) break;
      iVar5 = 0;
      iVar1 = 0;
    }
    puVar6 = (undefined4 *)(param_3 + 0x240);
    puVar8 = (undefined4 *)(param_1 + 0xc970);
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    FUN_0065f670(param_1);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0xd114) = 0;
    *(undefined4 *)(param_1 + 0xd318) = 0;
    *(undefined4 *)(param_1 + 0xd31c) = 0;
    *(undefined4 *)(param_1 + 0xd320) = 0;
    *(undefined4 *)(param_1 + 0xd358) = 0;
    *(undefined4 *)(param_1 + 0xd35c) = 0;
  }
  return iVar1;
}

