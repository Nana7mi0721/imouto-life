
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00516350(double *param_1,undefined1 param_2)

{
  double dVar1;
  int iVar2;
  double local_20;
  double local_18;
  double local_10;
  double local_8;
  
  if (DAT_00a388a0 == 0) {
    iVar2 = FUN_005857a0(&DAT_00a388a8,&DAT_00a387e0);
    dVar1 = _DAT_00805148;
    if (iVar2 < 0) {
      *param_1 = _DAT_00805148;
      param_1[1] = dVar1;
      param_1[2] = dVar1;
      return;
    }
    FUN_00584ff0(&DAT_00a38928,&DAT_00a388a8);
    DAT_00a388a0 = 1;
  }
  local_20 = 1.0;
  FUN_00586280(&local_18,&local_20,&param_2,&local_20,&DAT_00a388a8);
  local_20 = 1.0 / local_20;
  *param_1 = local_18 * local_20;
  param_1[1] = local_10 * local_20;
  param_1[2] = local_8 * local_20;
  return;
}

