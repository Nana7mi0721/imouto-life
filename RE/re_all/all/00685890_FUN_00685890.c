
int FUN_00685890(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = param_1[1];
  if (0x3b9ac9f0 < param_3) {
    FUN_006859c0(param_1,1);
  }
  if ((param_3 & 7) != 0) {
    param_3 = param_3 + (8 - (param_3 & 7));
  }
  if ((param_2 < 0) || (1 < param_2)) {
    *(undefined4 *)(*param_1 + 0x14) = 0xf;
    *(int *)(*param_1 + 0x18) = param_2;
    (**(code **)*param_1)(param_1);
  }
  puVar2 = (undefined4 *)0x0;
  puVar3 = *(undefined4 **)(iVar1 + 0x34 + param_2 * 4);
  do {
    if (puVar3 == (undefined4 *)0x0) {
LAB_00685912:
      iVar5 = param_3 + 0x10;
      if (puVar2 == (undefined4 *)0x0) {
        uVar4 = *(uint *)(&DAT_008230ec + param_2 * 4);
      }
      else {
        uVar4 = *(uint *)(&DAT_008230f4 + param_2 * 4);
      }
      if (1000000000U - iVar5 < uVar4) {
        uVar4 = 1000000000U - iVar5;
      }
      puVar3 = (undefined4 *)FUN_00687650(param_1,uVar4 + iVar5);
      while (puVar3 == (undefined4 *)0x0) {
        uVar4 = uVar4 >> 1;
        if (uVar4 < 0x32) {
          FUN_006859c0(param_1,2);
        }
        puVar3 = (undefined4 *)FUN_00687650(param_1,uVar4 + iVar5);
      }
      *(uint *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) + uVar4 + iVar5;
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = uVar4 + param_3;
      if (puVar2 == (undefined4 *)0x0) {
        *(undefined4 **)(iVar1 + 0x34 + param_2 * 4) = puVar3;
      }
      else {
        *puVar2 = puVar3;
      }
LAB_006859a4:
      iVar1 = puVar3[1];
      puVar3[1] = iVar1 + param_3;
      puVar3[2] = puVar3[2] - param_3;
      return iVar1 + 0x10 + (int)puVar3;
    }
    if (param_3 <= (uint)puVar3[2]) {
      if (puVar3 != (undefined4 *)0x0) goto LAB_006859a4;
      goto LAB_00685912;
    }
    puVar2 = puVar3;
    puVar3 = (undefined4 *)*puVar3;
  } while( true );
}

