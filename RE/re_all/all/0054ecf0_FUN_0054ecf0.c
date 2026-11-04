
undefined4 FUN_0054ecf0(char *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 local_448 [266];
  undefined4 local_20;
  undefined4 local_1c;
  int local_14;
  
  if (param_1[0xb] != '\0') {
    if (*param_1 != '\0') {
      iVar3 = FUN_00546d90(param_1,1);
      if (iVar3 < 0) {
        return 0xffffffff;
      }
    }
    if (((((param_1[5] != ' ') || (param_1[4] != '\x04')) || (param_1[3] != '\0')) ||
        ((*(int *)(param_1 + 0x20) != 0 || (*(int *)(param_1 + 0x1c) != -0x1000000)))) ||
       ((*(int *)(param_1 + 0x10) != 0xff0000 ||
        ((*(int *)(param_1 + 0x14) != 0xff00 || (*(int *)(param_1 + 0x18) != 0xff)))))) {
      uVar2 = *(undefined4 *)(param_1 + 0x42c);
      pcVar6 = param_1;
      puVar8 = local_448;
      for (iVar3 = 0x110; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar8 = *(undefined4 *)pcVar6;
        pcVar6 = pcVar6 + 4;
        puVar8 = puVar8 + 1;
      }
      FUN_00546c90(*(undefined4 *)(param_1 + 0x428),uVar2,param_1);
      FUN_0054eb60(0,0,local_20,local_1c,0,0,local_448,param_1);
      if (local_14 != 0) {
        FUN_0056e1d0(local_14);
        local_14 = 0;
      }
      FUN_0056d380(local_448,0,0x440);
    }
    uVar9 = 0;
    if (*(int *)(param_1 + 0x42c) != 0) {
      uVar5 = *(uint *)(param_1 + 0x428);
      do {
        puVar4 = (undefined1 *)(*(int *)(param_1 + 0x430) * uVar9 + *(int *)(param_1 + 0x434));
        uVar7 = 0;
        if (uVar5 != 0) {
          do {
            uVar1 = puVar4[3];
            *puVar4 = (&DAT_00a52a60)[CONCAT11(*puVar4,uVar1)];
            puVar4[1] = (&DAT_00a52a60)[CONCAT11(puVar4[1],uVar1)];
            puVar4[2] = (&DAT_00a52a60)[CONCAT11(puVar4[2],uVar1)];
            uVar5 = *(uint *)(param_1 + 0x428);
            uVar7 = uVar7 + 1;
            puVar4 = puVar4 + 4;
          } while (uVar7 < uVar5);
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(param_1 + 0x42c));
    }
  }
  return 0;
}

