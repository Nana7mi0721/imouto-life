
int FUN_00575210(undefined1 *param_1,uint param_2,undefined2 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  uint uVar5;
  int local_4;
  
  uVar2 = param_4;
  uVar1 = param_2;
  uVar5 = 0;
  local_4 = 0;
  if (param_4 < 2) {
    return 0;
  }
  if ((int)param_2 < 0) {
    iVar3 = CONCAT31(CONCAT21(CONCAT11(*param_1,param_1[1]),param_1[2]),param_1[3]);
    puVar4 = param_1;
    while (param_1 = (undefined1 *)iVar3, param_1 != (undefined1 *)0x0) {
      FUN_00573de0(&param_3,&param_1,&local_4,uVar2);
      iVar3 = CONCAT31(CONCAT21(CONCAT11(puVar4[4],puVar4[5]),puVar4[6]),puVar4[7]);
      puVar4 = puVar4 + 4;
    }
  }
  else if (param_2 != 0) {
    puVar4 = param_1 + 2;
    do {
      uVar5 = uVar5 + 1;
      param_1 = (undefined1 *)CONCAT31(CONCAT21(CONCAT11(puVar4[-2],puVar4[-1]),*puVar4),puVar4[1]);
      if (param_1 == (undefined1 *)0x0) break;
      FUN_00573de0(&param_3,&param_1,&local_4,uVar2);
      puVar4 = puVar4 + 4;
    } while (uVar5 < uVar1);
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = 0;
  }
  return local_4 + 2;
}

