// Smart Pointers
 // w9.cpp

 #include <iostream>
 #include <fstream>
 #include <iomanip>
 #include <memory>
 #include <utility>
 #include "Element.h"
 #include "List.h"

 const int FWC =  5;
 const int FWD = 12;
 const int FWP =  8;

 w9::List<w9::Product> merge(const w9::List<w9::Description>& desc, const w9::List<w9::Price>& price) {
	 w9::List<w9::Product> priceList;

	//******* YOUR CODE GOES HERE ***********//
	  //description class holds product code and a user-friendly description
	 //price class holds product code and the current price. 

	//******* YOUR CODE GOES HERE ***********//
	 for (unsigned int i = 0; i < desc.size(); i++) {
		 for (unsigned int j = 0; j < price.size(); j++) {

			 //comparing elements in the two received lists for common product codes 
			 if (desc[i].code == price[j].code) {

				std::unique_ptr<w9::Product> p = std::make_unique <w9::Product>(desc[i].desc, price[j].price); //= std::make_unique <Product>();
				 //std::unique_ptr<w9::Product> p(new w9::Product(desc[i].desc, price[j].price));
				//w9::Product* p = new w9::Product(desc[i].desc, price[j].price);

				 p->validate();
				 priceList += std::move(p);
				// priceList += p; //
				// delete p;

			 }
			  
		 }

	 }

     return priceList;
 }

 int main(int argc, char** argv) {

	 std::ofstream ofs("Lab8Output.txt");

     std::cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         std::cout << argv[i] << ' ';
     }
     std::cout << std::endl;
     if (argc != 3) {
         std::cerr << "\n***Incorrect number of arguments***\n";
         return 1;
     }

     try {
		 w9::List<w9::Description> desc(argv[1]);
		 ofs << std::endl;
		 ofs << std::setw(FWC) << "Code" << std::setw(FWD) << "Description" << std::endl;
		 ofs << desc << std::endl;
     	 w9::List<w9::Price> price(argv[2]);
		 ofs << std::endl;
		 ofs << std::setw(FWC) << "Code" << std::setw(FWP) << "Price" << std::endl;
		 ofs << price << std::endl;
     	 w9::List<w9::Product> priceList = merge(desc, price);
		 ofs << std::endl;
		 ofs << std::setw(FWD) << "Description" << std::setw(FWP) << "Price" << std::endl;
		 ofs << priceList << std::endl;
	 }
	 catch (const std::string& msg) {
		 ofs << msg << std::endl;
	 }
	 catch (const char* msg) {
		 ofs << msg << std::endl;
	 }

     std::cout << "Results can be found in the Lab8Output.txt file\nPress any key to continue ... ";
     std::cin.get();

	 ofs.close();
}
