
undefined4 __thiscall FUN_0049b1d0(undefined4 param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  uVar1 = FUN_004ce080(param_1);
  if (uVar1 <= param_2) {
    param_2 = 0xffffffff;
  }
  if (param_2 < 0x80000000) {
    puVar3 = (undefined4 *)FUN_004ce990(param_2);
    uVar2 = *puVar3;
  }
  else {
    uVar2 = FUN_00543f70(0,0,0);
  }
  return uVar2;
}

