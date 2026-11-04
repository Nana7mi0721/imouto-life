
void __fastcall FUN_004d3d00(int *param_1)

{
  facet *pfVar1;
  
  if ((*param_1 != 0) &&
     (pfVar1 = std::locale::facet::_Decref((facet *)*param_1), pfVar1 != (facet *)0x0)) {
    (*(code *)**(undefined4 **)pfVar1)(1);
  }
  return;
}

