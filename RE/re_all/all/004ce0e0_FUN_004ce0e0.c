
void __thiscall FUN_004ce0e0(void *param_1,uint param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  uVar1 = FUN_004ce080();
  if (uVar1 <= param_2) {
    FID_conflict__Xran(param_1);
  }
  puVar2 = local_c;
  FUN_004ce060(local_8);
  iterator__operator_(puVar2,param_2);
  FUN_004d95b0();
  return;
}

