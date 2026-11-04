
int FUN_00536b30(int param_1,uint param_2,int *param_3,int *param_4,int *param_5,int param_6,
                int param_7)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_4;
  
  iVar3 = param_1;
  *param_3 = param_1;
  *param_4 = 0;
  *param_5 = 0;
  if (param_6 != 0) {
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0x90d98)) {
      puVar5 = (uint *)(param_1 + 0x90d9c);
      do {
        if (*puVar5 == param_2) {
          return iVar4 * 0x20 + 0x90d9c + param_1;
        }
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 8;
      } while (iVar4 < *(int *)(param_1 + 0x90d98));
    }
  }
  if (param_2 < 0x10000) {
    if (*(int *)(param_1 + 0xfd80 + param_2 * 8) != 0) {
      return *(int *)(param_1 + 0xfd84 + param_2 * 8);
    }
  }
  else {
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0x8fd80)) {
      puVar6 = (undefined4 *)(param_1 + 0x8fd84);
      do {
        if (*(uint *)*puVar6 == param_2) {
          return *(int *)(param_1 + 0x8fd84 + iVar4 * 4);
        }
        iVar4 = iVar4 + 1;
        puVar6 = puVar6 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x8fd80));
    }
  }
  iVar4 = FUN_00536310(1,&param_2,param_1,1);
  if (iVar4 != 0) {
    return iVar4;
  }
  do {
    iVar7 = 0;
    puVar5 = (uint *)(iVar3 + 0x92da0);
    while( true ) {
      if (*(int *)(iVar3 + 0x92d9c) <= iVar7) {
        if (param_7 == 0) {
          return iVar4;
        }
        FUN_0056bb10(PTR_DAT_0084ca38);
        return iVar4;
      }
      if ((((DAT_00cc5c60 == 0) || (uVar1 = *puVar5, (int)uVar1 < 0)) ||
          ((uVar1 & 0x7c000000) != DAT_00cc5c88)) ||
         (((DAT_00cc5c90 <= (int)(uVar1 & 0xffff) ||
           (piVar2 = *(int **)(DAT_00cc5c64 + (uVar1 & 0xffff) * 4), piVar2 == (int *)0x0)) ||
          ((*piVar2 * 0x10000 != (uVar1 & 0x3ff0000) || (piVar2[4] != 0)))))) break;
      iVar4 = FUN_00536b30(piVar2,param_2,param_3,&param_1,&local_4,param_6,0);
      if (iVar4 != 0) {
        *param_4 = *param_4 + *(int *)(iVar3 + 0x92da4 + iVar7 * 0xc) + param_1;
        *param_5 = *param_5 + *(int *)(iVar3 + (iVar7 * 3 + 0x24b6a) * 4) + local_4;
        return iVar4;
      }
      iVar7 = iVar7 + 1;
      puVar5 = puVar5 + 3;
      iVar4 = 0;
    }
    FUN_00536810(*(undefined4 *)(iVar3 + 4),*(undefined4 *)(iVar3 + 0x92da0 + iVar7 * 0xc));
  } while( true );
}

