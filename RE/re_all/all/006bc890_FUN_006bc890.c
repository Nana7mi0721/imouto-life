
int FUN_006bc890(undefined4 *param_1,byte *param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  
  if (param_2 == (byte *)0x0) {
    return -1;
  }
  uVar1 = *(uint *)(param_2 + 4);
  if ((((((uVar1 & 0xf) == 0) && (uVar2 = *(uint *)(param_2 + 8), (uVar2 & 0xf) == 0)) &&
       (uVar1 != 0)) && ((uVar1 < 0x100000 && (uVar2 != 0)))) &&
     ((uVar2 < 0x100000 && (*(int *)(param_2 + 0xc) + *(uint *)(param_2 + 0x14) <= uVar1)))) {
    if ((((((uint)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18)) <= uVar2) &&
          (*(uint *)(param_2 + 0x14) < 0x100)) &&
         ((uVar2 - *(int *)(param_2 + 0x10)) - *(int *)(param_2 + 0x18) < 0x100)) &&
        ((((-1 < *(int *)(param_2 + 0x2c) && (*(int *)(param_2 + 0x2c) < 3)) &&
          (-1 < *(int *)(param_2 + 0x30))) &&
         ((*(int *)(param_2 + 0x30) < 4 && (*(int *)(param_2 + 0x1c) != 0)))))) &&
       (*(int *)(param_2 + 0x20) != 0)) {
      puVar7 = param_1;
      for (iVar5 = 0x326c; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = 0;
        puVar7 = puVar7 + 1;
      }
      pbVar6 = param_2;
      puVar7 = param_1;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *(undefined4 *)pbVar6;
        pbVar6 = pbVar6 + 4;
        puVar7 = puVar7 + 1;
      }
      iVar5 = *(int *)(param_2 + 8);
      iVar3 = *(int *)(param_2 + 0x18);
      iVar4 = *(int *)(param_2 + 0x10);
      *(undefined1 *)(param_1 + 0xda) = 0xff;
      param_1[6] = (iVar5 - iVar3) - iVar4;
      FUN_006bc870(param_1);
      iVar5 = FUN_006bca40(param_1);
      if (-1 < iVar5) {
        iVar5 = FUN_006bd350(param_1,param_3);
        if (-1 < iVar5) {
          if ((*(int *)(param_2 + 0x3c) < 0) || (0x1f < *(int *)(param_2 + 0x3c))) {
            param_1[0xf] = 0x1f;
          }
          param_1[0xd4] = 0;
          param_1[0xd6] = 0xffffffff;
          param_1[0xd5] = 0;
          param_1[0xd7] = 0xffffffff;
          if ((*param_2 < 4) &&
             ((*param_2 != 3 || ((param_2[1] < 3 && ((param_2[1] != 2 || (param_2[2] == 0)))))))) {
            *(undefined1 *)((int)param_1 + 0x369) = 0;
            return 0;
          }
          *(undefined1 *)((int)param_1 + 0x369) = 1;
          return 0;
        }
      }
      FUN_006bd2f0(param_1);
      return iVar5;
    }
  }
  return -10;
}

