
void FUN_006508e0(int param_1,char *param_2,va_list param_3)

{
  if (param_1 != 0) {
    _fprintf((FILE *)&DAT_0084b758,&DAT_00a06b64,param_1);
  }
  _vfprintf((FILE *)&DAT_0084b758,param_2,param_3);
  _fprintf((FILE *)&DAT_0084b758,&DAT_00a06b54);
  return;
}

