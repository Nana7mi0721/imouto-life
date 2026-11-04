
/* Library Function - Single Match
    public: void __thiscall std::ios_base::clear(int,bool)
   
   Library: Visual Studio 2003 Release */

void __thiscall std::ios_base::clear(ios_base *this,int param_1,bool param_2)

{
  uint uVar1;
  int extraout_ECX;
  int unaff_EBP;
  int iVar2;
  undefined *puVar3;
  
  FUN_006c5130();
  uVar1 = *(uint *)(unaff_EBP + 8) & 0x17;
  *(uint *)(extraout_ECX + 8) = uVar1;
  uVar1 = *(uint *)(extraout_ECX + 0xc) & uVar1;
  if (uVar1 == 0) goto LAB_0050d7e5;
  if (*(char *)(unaff_EBP + 0xc) == '\0') {
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 2) != 0) {
        basic_string<>("ios_base::failbit set");
        *(undefined4 *)(unaff_EBP + -4) = 1;
        goto LAB_0050d774;
      }
      basic_string<>("ios_base::eofbit set");
      *(undefined4 *)(unaff_EBP + -4) = 2;
      runtime_error::runtime_error
                ((runtime_error *)(unaff_EBP + -0x78),
                 (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (unaff_EBP + -0x94));
      *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_007d4788;
      iVar2 = unaff_EBP + -0x78;
    }
    else {
      basic_string<>("ios_base::badbit set");
      *(undefined4 *)(unaff_EBP + -4) = 0;
LAB_0050d774:
      runtime_error::runtime_error
                ((runtime_error *)(unaff_EBP + -0x34),
                 (basic_string<char,std::char_traits<char>,std::allocator<char>_> *)
                 (unaff_EBP + -0x50));
      *(undefined ***)(unaff_EBP + -0x34) = &PTR_FUN_007d4788;
      iVar2 = unaff_EBP + -0x34;
    }
    puVar3 = &DAT_00848b58;
  }
  else {
    puVar3 = (undefined *)0x0;
    iVar2 = 0;
  }
  __CxxThrowException_8(iVar2,puVar3);
LAB_0050d7e5:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

