
undefined4 __fastcall FUN_0052c820(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined *puVar1;
  uint in_EAX;
  int iVar2;
  int *piVar3;
  
  if (param_4 == 0) {
    if (DAT_00cc76d0 == 0) {
      return 0xffffffff;
    }
    if ((int)in_EAX < 0) {
      return 0xffffffff;
    }
    if ((in_EAX & 0x7c000000) != DAT_00cc76f8) {
      return 0xffffffff;
    }
    if (DAT_00cc7700 <= (int)(in_EAX & 0xffff)) {
      return 0xffffffff;
    }
    piVar3 = *(int **)(DAT_00cc76d4 + (in_EAX & 0xffff) * 4);
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar3 * 0x10000 != (in_EAX & 0x3ff0000)) {
      return 0xffffffff;
    }
    if (piVar3[4] != 0) {
      return 0xffffffff;
    }
  }
  else {
    if (DAT_00cc76d0 == 0) {
      return 0xffffffff;
    }
    if ((int)in_EAX < 0) {
      return 0xffffffff;
    }
    if ((in_EAX & 0x7c000000) != DAT_00cc76f8) {
      return 0xffffffff;
    }
    if (DAT_00cc7700 <= (int)(in_EAX & 0xffff)) {
      return 0xffffffff;
    }
    piVar3 = *(int **)(DAT_00cc76d4 + (in_EAX & 0xffff) * 4);
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    if (*piVar3 * 0x10000 != (in_EAX & 0x3ff0000)) {
      return 0xffffffff;
    }
  }
  if (piVar3[0xc] == 0) {
    iVar2 = (*(code *)PTR_FUN_0084c9d0)(param_2,0,1,param_3 != 0);
    piVar3[0x15] = iVar2;
    if (iVar2 != 0) {
      piVar3[0xd] = (int)PTR_thunk_FUN_00571dd0_0084ca04;
      piVar3[0xe] = (int)PTR_FUN_0084ca08;
      piVar3[0xf] = (int)PTR_thunk_FUN_00571e60_0084ca0c;
      piVar3[0x10] = (int)PTR_DAT_0084ca10;
      piVar3[0x11] = (int)PTR_DAT_0084ca14;
      puVar1 = PTR_thunk_FUN_00571d20_0084ca18;
      piVar3[0x13] = iVar2;
      piVar3[0x12] = (int)puVar1;
      return 0;
    }
  }
  return 0xffffffff;
}

