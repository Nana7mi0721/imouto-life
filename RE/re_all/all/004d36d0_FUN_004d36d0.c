
int __thiscall FUN_004d36d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 local_10 [4];
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)FUN_004ce060(local_8);
    uVar2 = *puVar1;
    puVar1 = (undefined4 *)FUN_004cc870(local_c);
    FUN_004dda00(local_10,*puVar1,uVar2);
    FUN_004ddad0(param_2);
  }
  return param_1;
}

