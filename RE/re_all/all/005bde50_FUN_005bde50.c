
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005bde50(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  if (*(char *)(*(int *)(param_1 + 0x4c) + 0xb) == '\0') {
    return 2;
  }
  FUN_00568ca0(0);
  if (DAT_00dda46c != 0) {
    FUN_00584d70();
  }
  local_4 = (float)_DAT_0081ec30;
  iVar1 = 0;
  local_10 = (float)param_2 / local_4;
  local_c = (float)param_3 / local_4;
  local_8 = (float)param_4 / local_4;
  local_4 = (float)param_5 / local_4;
  if (0 < *(int *)(param_1 + 0x88)) {
    puVar2 = (undefined4 *)(param_1 + 0x100);
    do {
      FUN_005d2e00(**(undefined4 **)(*(int *)*puVar2 + 0xc),&local_10);
      iVar1 = iVar1 + 1;
      puVar2 = puVar2 + 0x1e;
    } while (iVar1 < *(int *)(param_1 + 0x88));
  }
  return 0;
}

