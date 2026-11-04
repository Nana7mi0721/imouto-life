
int FUN_00574e00(int *param_1,uint param_2,undefined2 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined2 *puVar5;
  uint uVar6;
  int local_4;
  
  uVar2 = param_4;
  uVar1 = param_2;
  uVar6 = 0;
  local_4 = 0;
  if (param_4 < 2) {
    return 0;
  }
  if ((int)param_2 < 0) {
    iVar3 = *param_1;
    piVar4 = param_1;
    while (param_1 = (int *)iVar3, param_1 != (int *)0x0) {
      piVar4 = piVar4 + 1;
      FUN_00573de0(&param_3,&param_1,&local_4,uVar2);
      iVar3 = *piVar4;
    }
  }
  else if (param_2 != 0) {
    puVar5 = (undefined2 *)((int)param_1 + 2);
    do {
      uVar6 = uVar6 + 1;
      param_1 = (int *)CONCAT31(CONCAT21(*puVar5,*(undefined1 *)((int)puVar5 + -1)),
                                *(undefined1 *)(puVar5 + -1));
      if (param_1 == (int *)0x0) break;
      FUN_00573de0(&param_3,&param_1,&local_4,uVar2);
      puVar5 = puVar5 + 2;
    } while (uVar6 < uVar1);
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = 0;
  }
  return local_4 + 2;
}

