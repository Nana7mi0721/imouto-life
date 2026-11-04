
int __fastcall FUN_005d6890(uint param_1)

{
  uint uVar1;
  
  uVar1 = (param_1 >> 1 & 0x55555555) + (param_1 & 0x55555555);
  uVar1 = (uVar1 >> 2 & 0x33333333) + (uVar1 & 0x33333333);
  uVar1 = (uVar1 >> 4 & 0xf0f0f0f) + (uVar1 & 0xf0f0f0f);
  uVar1 = (uVar1 >> 8 & 0xff00ff) + (uVar1 & 0xff00ff);
  return (uVar1 >> 0x10) + (uVar1 & 0xffff);
}

